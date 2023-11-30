# Tic-Tac-Toe-game-c++-
-Our game is a single player versus AI . it uses min-max algorithm to play the role of AI.<br />
-In a high level view we can look to our app as seperated parts<br />
  -1)Front-end which jop is to communicate with the user in app we achieve that through the console.<br />
  
  ![image](https://github.com/saeedmabrouk21/Tic-Tac-Toe-game-cpp/assets/73306180/117f5536-aba2-474c-933c-6d52fb1fcbdc)
  
  -2)Game-engine (The Device) it implements how the functionalites of game work (ex) how to save, how to load ..etc<br />
  -3)min-max Algortihm which nessarily used by Game engine <br />
-Now the Idea is how to connect these pieces<br />
  -1)Conect Front-end With game-engine : we Achieved that by using Command design battern it  encapsulates a request as an object, thereby letting us parameterize other objects with different requests.<br />
      To implement that we created differnt classes<br />
      ☼ **Front-end** class <br />
      ☼ **Tic-Tac_Toe** class which represnts Game-engine. It will contains implmentions of all commands<br />
      ☼ **ICommand** Interface which include a method excute<br />
      ☼ Different class for each command (**play**, **Save**, **Load** and **reset**) .each command uses the implmention in the Device class so it needs a device object or reference to device object<br />
      ☼ **Invoker** which responsible for execute commands - Inevitably front-end class owns Invoker object<br />
    so by this setup front end can create object of any commands and just pass to it refernce to device object then use invoker to execute the command<br />
    ![image](https://github.com/saeedmabrouk21/Tic-Tac-Toe-game-cpp/assets/73306180/ee32d829-b3ff-4af7-b9bd-1412896e92d8)



  
![image](https://github.com/saeedmabrouk21/Tic-Tac-Toe-game-cpp/assets/73306180/85298d2d-fb6a-40c1-9312-c0034d6c44c6)


