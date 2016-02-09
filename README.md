Couple notes about Fraction:
Basically these are all the supported operators:
+ - addition
- - subtraction
* - multiplication
/ - division
<< - insertion(for output stream)
== - equality
> - bigger than
< - smaller than
>= - bigger than or equals to
<= - smaller than equals to
float - explicit float cast(to avoid ambiguity)
+= addition assignment
-= subtraction assignment
*= multiplication assignment
/= division assignment
- unary negation operator
= copy assignment operator
That's about it.
There is a conversion constructor from int to Fraction.
There is a weird declaration of a float conversion constructor and a double conversion constructor as private members
in order to prevent such uses:

Fraction f1(1,2);
f1 *= 0.6 or f1 *= 0.6f

If the conversion constructor from float to fraction was not declared such uses would be acceptable - the compiler
will implicitly cast the float to int and then use the defined int conversion constructor(from int to fraction). So we get 0/1 in this case:
Fraction((int)0.6) = Fraction(0)

The code above will not compile because the conversion constructors are in fact private.

There is a conversion from Fraction to float but it is declared with explicit keyword to resolve ambiguity problems.
