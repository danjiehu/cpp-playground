### 1. What is the big(o) notation, what problem does it solve?

The big(o) notation quantifies the qualitfy of an algorithm, from the `output efficiency: time consumption` *(NOT the absolute time but summarized time from how many steps it takes)* to the `input quantity: data quantity to be processed` perspective.

Different o(n?) is considered to have different quality. O(n?) represents the math relation between **the number of steps that the algorithm takes to resolve** as **the algorithm's input reaches infinite**. We can easily draw the lines in a cartesian coordinate system, as the Big-O Complexity Chart below. It's easy to see that, the steeper the line, the faster the program gets slower (as steeper the line, for the same `Δx`, `Δy` is bigger), the worse we consider the algorithm to be.

*Big-O Complexity Chart:* 

![Understanding time complexity with Python examples | by Kelvin Salton do  Prado | Towards Data Science](https://miro.medium.com/max/1200/1*5ZLci3SuR0zM_QlZOADv8Q.jpeg)

### 2. How to evaluate a function's big O if it contains multiple functions?

For functions that contain multiple other functions, we can measure its efficiency by evaluating each sub-function individually. The sub-function that has worst O(n?), as Big-O Complexity Chart indicates, for example O(n!), will be the function's big O category. The math behind it is how we calcualte limit at infinity, for example,

 ![img](http://www.sciweavers.org/upload/Tex2Img_1638079954/render.png)

### ref

* math equation image generator http://www.sciweavers.org/free-online-latex-equation-editor
* find the limite at infinity https://www.youtube.com/watch?v=nViVR1rImUE
* representing the imit (mathematics) sign? https://tex.stackexchange.com/questions/74969/how-to-make-the-limit-mathematics-sign
