# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tingwei/Cpp_TUT/CMakeList_TUT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tingwei/Cpp_TUT/CMakeList_TUT/build

# Include any dependencies generated for this target.
include src/CMakeFiles/DisplayImage.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/DisplayImage.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/DisplayImage.dir/flags.make

src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o: src/CMakeFiles/DisplayImage.dir/flags.make
src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o: ../src/DisplayImage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tingwei/Cpp_TUT/CMakeList_TUT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o"
	cd /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o -c /home/tingwei/Cpp_TUT/CMakeList_TUT/src/DisplayImage.cpp

src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/DisplayImage.cpp.i"
	cd /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tingwei/Cpp_TUT/CMakeList_TUT/src/DisplayImage.cpp > CMakeFiles/DisplayImage.dir/DisplayImage.cpp.i

src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/DisplayImage.cpp.s"
	cd /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tingwei/Cpp_TUT/CMakeList_TUT/src/DisplayImage.cpp -o CMakeFiles/DisplayImage.dir/DisplayImage.cpp.s

src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.requires:

.PHONY : src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.requires

src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.provides: src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/DisplayImage.dir/build.make src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.provides.build
.PHONY : src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.provides

src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.provides.build: src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o


# Object files for target DisplayImage
DisplayImage_OBJECTS = \
"CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o"

# External object files for target DisplayImage
DisplayImage_EXTERNAL_OBJECTS =

../lib/libDisplayImage.so: src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o
../lib/libDisplayImage.so: src/CMakeFiles/DisplayImage.dir/build.make
../lib/libDisplayImage.so: /usr/local/lib/libopencv_stitching.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_superres.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_videostab.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_aruco.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_bgsegm.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_bioinspired.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_ccalib.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_dpm.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_face.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_freetype.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_fuzzy.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_hdf.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_img_hash.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_line_descriptor.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_optflow.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_reg.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_rgbd.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_saliency.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_sfm.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_stereo.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_structured_light.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_surface_matching.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_tracking.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_xfeatures2d.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_ximgproc.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_xobjdetect.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_xphoto.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_photo.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_datasets.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_plot.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_text.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_dnn.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_ml.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_shape.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_video.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_calib3d.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_features2d.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_highgui.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_videoio.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_viz.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_phase_unwrapping.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_flann.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_imgcodecs.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_objdetect.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_imgproc.so.3.3.1
../lib/libDisplayImage.so: /usr/local/lib/libopencv_core.so.3.3.1
../lib/libDisplayImage.so: src/CMakeFiles/DisplayImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tingwei/Cpp_TUT/CMakeList_TUT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libDisplayImage.so"
	cd /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DisplayImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/DisplayImage.dir/build: ../lib/libDisplayImage.so

.PHONY : src/CMakeFiles/DisplayImage.dir/build

src/CMakeFiles/DisplayImage.dir/requires: src/CMakeFiles/DisplayImage.dir/DisplayImage.cpp.o.requires

.PHONY : src/CMakeFiles/DisplayImage.dir/requires

src/CMakeFiles/DisplayImage.dir/clean:
	cd /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src && $(CMAKE_COMMAND) -P CMakeFiles/DisplayImage.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/DisplayImage.dir/clean

src/CMakeFiles/DisplayImage.dir/depend:
	cd /home/tingwei/Cpp_TUT/CMakeList_TUT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tingwei/Cpp_TUT/CMakeList_TUT /home/tingwei/Cpp_TUT/CMakeList_TUT/src /home/tingwei/Cpp_TUT/CMakeList_TUT/build /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src /home/tingwei/Cpp_TUT/CMakeList_TUT/build/src/CMakeFiles/DisplayImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/DisplayImage.dir/depend

