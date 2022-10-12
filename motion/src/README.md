#### Notes:

To run this node:
  - run  ``catkin_make`` on the workspace root directory;
  - And ``rosrun motion turtlesim_move``

This one was made with an OOP approach. So, in order to set up the header file, and it's dependencies:

  - Specify additional specific location of the header file in the ``CMakeLists.txt`` so that the compiler search it directly instead of writing the entire path to the header file. It can be done in the ``include_directories`` zone;

![header_location](https://user-images.githubusercontent.com/74921179/195239994-62f4c9ac-b599-4b76-b352-f79716dfa7f0.png)

  - Next, in the same file, declare a library with the rule ``add_library(${LIBRARY_NAME} ${PATH_TO_DEPENDENCIES})``, and then link the catkin libraries with the rule ``target_link_libraries(${LIBRARY_NAME} ${catkin_LIBRARIES})``;

![rules](https://user-images.githubusercontent.com/74921179/195241172-71680ce0-8c4d-4067-a991-502e77afb383.png)

  - At this point, the project should not be linked to ``${catkin_LIBRARIES}`` but to ``${LIBRARY_NAME}``

![turtle_link](https://user-images.githubusercontent.com/74921179/195241431-d02c5a98-4f8c-4ff1-baa5-e76f8f46eeb2.png)
