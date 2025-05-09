# What is an ARFrameholder? 

## Context? 
In an AR pipeline, video frames are generated rapidly from a camera (via the embedded layer) then passed to various processing steps: 

 - Feature detection (OpenCV)
 - Scene analysis 
 - Overlay rendering 
 - Etc. 

If each step copid the frame, the pipeline would be too slow and memory-hungry 

### So we need: 

 - Shared ownership of each frame so that many processors can view it 
 - Clear lifetime management (when the last process is done it auto-deletes)
 - RAII and exception safety, so even if one step throws we dont leak or crash 

--- 

Thats where this **ARFrameHolder** comes in: 
Its a class that wraps a 'cv::Mat' (or mock frame), managing it via 'std::shared_ptr' and exposing it to other modules safely.

