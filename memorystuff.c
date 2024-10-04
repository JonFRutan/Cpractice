//These are some notes taken about memory management in C programming.
//Notes are taken from Eskil Steenberg's video "How I program C"

float *a;     //This is a pointer to a double.
a = malloc(sizeof(float)); //In general, we would use this to allocate the size of a float.
//OR
a = malloc((sizeof *a)); //This is more versatile, as instead of using the literal type in our sizeof call, we can now change 'a' if needed and this will still work.

//A struct is a sizeof, and various offsets.
//When compiled, structs lose their names and simply become data values in a range of memory.
typedef struct {
    uint type;
    char name[32];
    float size;
}MyStructType;
//Here let's say we wanted to find how far into our struct the 'size' field is.
offset = (uint)(&((MyStructType *)NULL)->size);
//'offset' is how far into our struct the size field is.
//What we are doing here, is initializing a pointer to our struct to NULL, or the beginning of the allocated memory.
//With '->size' we are derefrencing the size field out of the pointer.
//We then use the '&' to tell the program we want the memory address of this field.
//Finally, we cast it into an unsigned integer to give us the offset value of the field in memory.


//Alignment
//What is alignment? - In C data size likes to be on an factor of its sized address. 
//For example:
typedef struct {
    uint8 a;  //1 byte
    utin32 b; //4 bytes
}MyStructType;
//So 5 bytes right? Not really, this is how the data is actually laid out: a***bbbb
//Since 'a' only takes 1 byte, it fills in it's byte, then is empty for another 3. Then our 32 bit 'b' fills in it's 4 on the 5-9 indexes.
//Alignment is the prioritization of data to align on a factor of it's needed space. 4 bytes wants to be at index 0, or 4, or 8, or 12, etc.
//Why does this matter? Because we can take advantage of this empty space instead of just wasting it.
typedef struct {
    uint8 a;   //1 byte
    uint8 x;   //1 byte
    utin8 y;   //1 byte
    uint8 z;   //1 byte
    uint32 b;  //4 bytes
}MyProperStructType;
//8 bytes right? Yes. Not the data is laid out as such: axyzbbbb
//It takes up the same amount of bytes as our other struct, but properly fills in and provides more values to be used, thus not wasting memory.
//HOWEVER - The ordering of the data values matters. For example:
typedef struct {
    uint32 b; //4 bytes
    uint8 a;  //1 byte
}MyImproperStructType;
// bbbba*** - Why does it still pad? Because generally we aren't just allocating space for 1 struct, but multiple.
// Allocating even 2 would yield: bbbba***bbbba*** - This is because the data still seeks alignment when allocating all the space.
// Meaning that our 4 bytes is still always looking for a factor of 4 to start on.
// One last example on ordering:
typedef struct {
    uint8 a; //1 byte
    uint32 b;//4 bytes
    uint8 z; //1 byte
}MySillyStructType;
// a***bbbbz*** - Horrific isn't it? Ordering within your struct matters quite a bit due to data alignment. Proper usage would be:
typedef struct {
    uint8 a;  //1 byte
    uint8 z;  //1 byte
    uint32 b; //4 bytes
}MyFixedStructType;
//az**bbbb - While we are still losing 2 bytes, this is far more practical than the prior struct layout since we have saved 4 bytes overall.