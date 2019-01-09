# old_classwork_cs352_unix_programming
Looks like summer 2004 -- C/C++ stuff on Linux
```
hw2 -- knight.c -- looks like it draws the legal moves for a knight piece in Chess on an arbitrarily-sized board, e.g.
$ ./knight 
Board size: 10
Knight row: 2
Knight column: 4
+---+---+---+---+---+---+---+---+---+---+
|   | * |   |   |   | * |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   | K |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   | * |   |   |   | * |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   | * |   | * |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
$ ./knight 
Board size: 10
Knight row: 6
Knight column: 6
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   | * |   | * |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   | * |   |   |   | * |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   | K |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   | * |   |   |   | * |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   | * |   | * |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+

mitsubishi draws their logo in arbitrary size (kinda 'banner'-like):

$ ./mit 
10
                   *
                  ***
                 *****
                *******
               *********
              ***********
             *************
            ***************
           *****************
          *******************
           *****************
            ***************
             *************
              ***********
               *********
                *******
                 *****
                  ***
                   *
         ********** **********
        **********   **********
       **********     **********
      **********       **********
     **********         **********
    **********           **********
   **********             **********
  **********               **********
 **********                 **********
**********                   **********

$ ./mit 
20
                                       *
                                      ***
                                     *****
                                    *******
                                   *********
                                  ***********
                                 *************
                                ***************
                               *****************
                              *******************
                             *********************
                            ***********************
                           *************************
                          ***************************
                         *****************************
                        *******************************
                       *********************************
                      ***********************************
                     *************************************
                    ***************************************
                     *************************************
                      ***********************************
                       *********************************
                        *******************************
                         *****************************
                          ***************************
                           *************************
                            ***********************
                             *********************
                              *******************
                               *****************
                                ***************
                                 *************
                                  ***********
                                   *********
                                    *******
                                     *****
                                      ***
                                       *
                   ******************** ********************
                  ********************   ********************
                 ********************     ********************
                ********************       ********************
               ********************         ********************
              ********************           ********************
             ********************             ********************
            ********************               ********************
           ********************                 ********************
          ********************                   ********************
         ********************                     ********************
        ********************                       ********************
       ********************                         ********************
      ********************                           ********************
     ********************                             ********************
    ********************                               ********************
   ********************                                 ********************
  ********************                                   ********************
 ********************                                     ********************
********************                                       ********************

```
