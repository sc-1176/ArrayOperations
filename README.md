# ArrayOperations

This project is a collection of four total functions that mess with arrays. It reads input from an input file, (ArrayData.txt) and outputs directly into the console.
I've included a standard test array and called all included functions in the Source cpp file, testing can be done quickly by uncommenting the function call you wish to test.
These also serve as a template should you want to build your own array/test multiple arrays at once. Any outstanding limitations that weren't mentioned in this file are in the project's comments.
Also, please ignore anything that looks odd. I haven't used github before now.

PLEASE NOTE: Your array, if you choose to modify the input file, cannot exceed 50 columns or 50 rows. The stack will corrupt. Your indexes will be between 0 and 49 because of this.

The functions included:
- Searching a 2-D array for a value then returning the index of said value

  Example output:
  
  ![image](https://user-images.githubusercontent.com/124931156/217935124-c070cc74-f7b3-49ee-92cd-f23ca2c8f1cf.png)

  Using input:
  
  ![image](https://user-images.githubusercontent.com/124931156/217935297-eab7825c-ae69-4c4e-9b83-dca13e2a2034.png)


- Add to an existing array, prompting the user to enter in values to fill the new empty array while displaying the index. The amount of rows/columns added MUST be positive - this function does not decrease the size of an array.

  Example output:
  
  ![image](https://user-images.githubusercontent.com/124931156/217936205-ba2ebfca-84d8-4675-9ba1-a104b64e3d3d.png)

  Using input:
  
  ![image](https://user-images.githubusercontent.com/124931156/217936354-22fd7b80-3fc0-4466-987b-5f552f5bdd6b.png)


-Replacing the value of an existing item in the array given its index

  Example output:
  
  ![image](https://user-images.githubusercontent.com/124931156/217936970-639d3c14-68d2-46c7-a8d3-4783ebc3a554.png)

  Using input:
  
  ![image](https://user-images.githubusercontent.com/124931156/217937021-4ffb86c9-7bd3-488f-929e-8d0b918362ec.png)


- Value nuke, turns any value, given the index, to '0'
 
  Example output:
  
  ![image](https://user-images.githubusercontent.com/124931156/217937266-c7b67032-a6f5-4451-ab54-36fe85f89155.png)

  Using input:
  
  ![image](https://user-images.githubusercontent.com/124931156/217937353-c391f1cb-f451-4206-928d-a01256d06310.png)
  
  
- Display function

  For examples of this, see the above printed matrices.
