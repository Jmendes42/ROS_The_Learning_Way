### Challenges folder

All the challenges where made in C++ (src folder) and Python (script folder)

#### Notes:

To create this package used the `catkin_create_pkg` with the dependencies `roscpp`, `rospy` and `std_msgs`

`catkin_create_pkg <package_name> <dependencies>`

![Screenshot from 2022-09-15 17-28-46](https://user-images.githubusercontent.com/74921179/190457920-1b45c3c6-4cde-49bf-bd7c-88cf215567c1.png)


### C++ files

#### Notes:

To declare a C++ executable add the following line to file `CMakeLists.txt` :

`add_executable(${PROJECT_NAME}_node ${PATH} ${FILE_NAME})`

To specify libraries to link a library or executable target:

`target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})`

![Screenshot from 2022-09-15 19-33-25](https://user-images.githubusercontent.com/74921179/190483365-f07e13d3-4616-4809-8f3c-6e17a68c434f.png)


To create executables use the command ```catkin_make``` in catkin_ws folder

![cmake](https://user-images.githubusercontent.com/74921179/193732112-72e952f0-499f-4d37-bbf1-d883d23124b4.png)
