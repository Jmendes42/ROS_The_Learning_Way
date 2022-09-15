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
