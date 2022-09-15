## Services 

#### ROS Services:

  - A ROS service is a client/server system
  - Is synchronous (the client sends a request and block's until it gets a response)
  - It's used for computations and quick actions
  - One message type for Request, and one message type for Response
  - A service can only exist once, but can have many clients

#### The challenge:

  - Create a service to reset the number counter of the Topic's challenge with std_srvs/SetBool;

![Screenshot from 2022-09-15 15-10-50](https://user-images.githubusercontent.com/74921179/190426122-a051013c-6e3e-4be0-ac50-0e1248824b62.png)


For this I needed to add the `std_srvs` package the challenge package folder.
To add a dependecie on an existent package go the `CMakeLists.txt` inside it and add `<package_name>` to the `Find catkin macros and libraries` zone

![Screenshot from 2022-09-15 17-33-53](https://user-images.githubusercontent.com/74921179/190458868-6275cd83-61a0-40cd-90d4-2b0e1534c5bb.png)

And on the `package.xml` file added:

`<build_depend>package_name</build_depend>`

`<build_export_depend>package_name</build_export_depend>`

`<exec_depend>package_name</exec_depend>`

![Screenshot from 2022-09-15 17-37-09](https://user-images.githubusercontent.com/74921179/190459479-6e559aba-f2ec-4ea3-a748-0ecb4a3c8de8.png)
