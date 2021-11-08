# VideoMaster
A simple GUI software for exploring and enjoying videos.

## Usage:
* Enter a video file with an `.mp4` extension to the "Video File" input, or, browse with a file dialog interface.
* Open the video file by clicking "Open".
* There are 2 main modes and a total of 4 modes. Modes are controlled by 3 checkboxes that are labelled as "Enable", "Loop" and "Reverse". A mode is activated according to boxes that are checked when you press the "Apply" button. Once a mode starts running, you can close it by pressing "Q" while the output window is being focused.
  * **Free Mode**: 
    * Activated when none of the boxes are checked.
    * In this mode you can freely traverse video frames.
    * Press 'D' key to increase frame index.
    * Press 'A' key to decrease frame index.
    * You can adjust the step size of increments and decrements from "Step" input.
    * You can start traversing from a specific frame index using "Jump" input.
    * Changing image processing settings while at a frame will only be in effect after pressing either 'A' or 'D'.
    * You can save the current frame by clicking "Save Current Frame" button. Please enter a valid saving folder path to the corresponding input, or, adjust the default saving directory during build. Don't forget to press "Set" button if you enter a saving directory path from the input.
  * **Boomerang & Loop Mode**:
    * Boomerang mode is activated when *only* "Enable" box is checked.
    * Loop mode is activated when *only* "Enable" and "Loop" boxes are checked.
    * Reverse loop mode is activated when all three boxes are checked.
    * Let `from` and `to` correspond to two frame indices where `from < to`.
    * In Boomerang mode, frame index starts from `from`, goes to `to` frame by frame, then returns to `from` as the same way, and repeats.
    * In Loop mode, frame index starts from `from`, goes to `to` frame by frame, then *jumps back* to `from`, and repeats.
    * In Reverse Loop mode, frame index starts from `to`, goes to `from` frame by frame, then *jumps back* to `to`, and repeats.
    * You can change delay between frames (in milliseconds) while these modes are running, you need to stop and re-run the mode again if you want to change image processing parameters.
    * You cannot exit these modes during their loading time.
    * You cannot save frames during these modes.

## Notes:
* You will need OpenCV and QT to build this software. I am using OpenCV 4.4.0 and QT MSVC 5.15.0.
* There are parts of the source code that need to be adjusted to your system. Please do a global text search with the key `--change` to see where.
* Also, do a global text search with the key `--optional` and decide yourself if you want to change those.

