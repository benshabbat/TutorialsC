/*
Implementing (sort of) strupr yourself!
Take a look on the attached ASCII table: what is the distance (in numbers) between ‘a’ and ‘A’ ? Between ‘b’ and ‘B’? Is it the same for all letters? Let’s use it for writing the following function:

char to_upper(char ch);

That gets a character and returns it’s capital form (warning: the input might be already in capital form! )
*/

char to_upper(char ch) {
    if(ch >= 'a' && ch <= 'z') return ch - ('a' - 'A');
    else return ch;
}