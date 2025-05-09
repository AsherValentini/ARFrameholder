#include <iostream>
#include <memory>

#include "ar_frame_holder.h"

void simulateProcessingShared(std::shared_ptr<ARFrameHolder::FrameData> frame) {
    // Simulate processing the frame data when passed up the pipeline as a shared pointer 
    std::cout << "[Shared] Processing frame data of size: " << frame->size() << std::endl;

}

void simulateProcessingWeak(std::weak_ptr<ARFrameHolder::FrameData> weakFrame){
    // Simulate processing the frame data when passed up the pipeline as a weak pointer
    if(auto frame = weakFrame.lock()) {
        std::cout << "[Weak] Safely locked and processing frame of size: " << frame->size() << std::endl;
    }else {
        std::cout << "[Weak] Frame has expired. Cannot process." << std::endl; 
    }
}

int main() {

    std::weak_ptr<ARFrameHolder::FrameData> weak1; // we need to declare the weak pointer outside the scope

    {
        // Crreate the mock frame data 
        auto rawFrame = std::make_shared<ARFrameHolder::FrameData>(1024, 255);

        // Wrapt it in the ARFrameHolder class 
        ARFrameHolder holder(std::move(rawFrame));

        // Simulate shared access 
        auto shared1 = holder.getShared(); 
        simulateProcessingShared(shared1); 

        {
            auto shared2 = holder.getShared(); 
            simulateProcessingShared(shared2); 
            std::cout << "[Main] shared2 use_count: " <<shared2.use_count() << std::endl;
        }

        // Simulate weak access 
        weak1 = holder.getWeak(); 
        simulateProcessingWeak(weak1);

        // Drop the last shared pointer 
        shared1.reset(); // now no one owns the frame 
    }
    // Try the weak access again 
    simulateProcessingWeak(weak1); // this should fail since the weak pointer is no longer valid 

    std::cout << "[Main] Done .\n";
    return 0; 
}