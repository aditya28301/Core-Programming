T function_name(T1 n1, T2 n2, ..., Tk nk){


    return (expr); 
}

// what has been taught? 
// type(expr) MUST BE T 

// TRUTH: many times: type(expr) is T 
// but IT MAY NOT BE SO and STILL THE DECLARATION MAY BE CORRECT CORRECT

// RETURN TYPE T: DOES NOT ENFORCE type T on 'expr' written after return statement 

// RATHER IT DENOTES A TYPE OF A VARIABLE NAME TO WHICH CALL TO FUNCTION WILL BE ASSIGNED 


//v = function_name(objT1, obj2, ...., objTk); 

//what type variable 'v' should have? The answer it T. 

//IT WILL WORK ONLY WHEN expr can be assigned to variable of type T. 

//type(expr) SHOULD BE COMPATIBLE WITH T. 

//if type(expr) is T then T is COMPATIBLE WITH T. 
// but if type (expr) is not T but assignable to variable 
// of type T then it will work. 

// INSIDE COM by DEL RODGERSON 
// ESSENTIAL COM BY DON BOX 

// INSIDE OLE 2.0 KRAIG BROCKSCHMIDT