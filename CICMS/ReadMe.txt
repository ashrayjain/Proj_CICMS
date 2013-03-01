========================================================================
    APPLICATION : CICMS Project Overview
========================================================================

Group members: XIE KAI, ASHRAY JAIN, BOB WONG, HUI HUI

addPdForm.cpp: Contains the class implementation of addPdForm, which creates a window that receives new product details. It contains get_product_details(), which when called, returns the details of the product.

addPdForm.h: Contains the class specification of addPdForm.

inputForm.cpp: Contains the class implementation of inputForm, which creates a window that receives a number for various purposes. These purposes are listed as such: 
The number of unique products to add
The number of a single product sold
The number by which a single product is restocked

inputForm.h: Contains the class specification of inputForm.

ListViewItemComparer.cpp: Contains the class implementation of ListViewItemComparer. This is used by mainForm to sort the items in the displayed list alphabetically.

ListViewItemComparer.h: Contains the class definition of ListViewItemComparer.

logic.cpp: Contains the class implementation of logic. This contains a number of functions which are used to search, add, delete, restock, and convert the ListViewItem object returned from addPdForm to a Product object for search and handling by internal logic functions.

logic.h: Contains the class specification of logic.

main.cpp: Creates mainForm and does miscellaneous GUI stuff.

mainForm.cpp: Contains the class implementation of mainForm, which creates the main window. Contains numerous elements which trigger the creation of addPdForm and inputForm objects, in addition to displaying data returned from the logic object.

mainForm.h: Contains the class specification of mainForm.

Product.cpp: Contains the class implementation of the Product object, which includes functions to return specific values of the Product object.

Product.h: Contains the class specification of the Product object.

 
 