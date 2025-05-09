#include "ar_frame_holder.h"

ARFrameHolder::ARFrameHolder(std::shared_ptr<FrameData> frame) 
    : frame_(std::move(frame)) {} // the reason we use move is to avoid copying the shared pointer, which would increase the reference count unnecessarily.

std::shared_ptr<ARFrameHolder::FrameData> ARFrameHolder::getShared() {
    return frame_; 
}

std::weak_ptr<ARFrameHolder::FrameData> ARFrameHolder::getWeak() {
    return frame_;
}