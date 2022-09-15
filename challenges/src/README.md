### C++ files

#### Notes:

To declare a C++ executable add the following line to file `CMakeLists.txt` :

`add_executable(${PROJECT_NAME}_node ${PATH} ${FILE_NAME})`

To specify libraries to link a library or executable target:

`target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})`

![Screenshot from 2022-09-15 14-22-47](https://user-images.githubusercontent.com/74921179/190414961-ae863b91-3ce3-4772-8743-f97a2e9af53c.png)
