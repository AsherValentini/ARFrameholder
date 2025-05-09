#pragma once
#include <memory>
#include <vector>
#include <cstdint>

class ARFrameHolder {

public: 
    using FrameData = std::vector<uint8_t>; // lets make an alias for the frame data type so that we do not have to use std::vector<uint8_t> everywhere 

    ARFrameHolder(std::shared_ptr<FrameData> frame); 

    std::shared_ptr<FrameData> getShared(); 
    std::weak_ptr<FrameData> getWeak(); 

private: 
    std::shared_ptr<FrameData> frame_; 

};