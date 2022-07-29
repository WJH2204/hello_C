//
//#include <stdio.h>
//#include <string.h>
//
//void replaceSpace(char* str, int length) {
//    int i = 0;
//    int numspace = 0;
//    for (i = 0; i < length; i++)
//    {
//        if (*(str+i) == ' ')
//        {
//            numspace++;
//        }
//    }
//    int j = 0;
//    for (i = length - 1; i >= 0; i--)
//    {
//        if (*(str + i) == ' ')
//        {
//            memmove(str + i + 1 + 2 * numspace, str + i + 1, j);
//            memmove(str + i + 1 + 2 * numspace - 3, "%20", 3);
//            j = -1;
//            numspace--;
//        }
//        j++;
//    }
//
//}
//
//int main()
//{
//    char str[100] = "we are happy";
//    
//    replaceSpace(str, strlen(str));
//
//    printf("%s\n", str);
//	return 0;
//}
//
