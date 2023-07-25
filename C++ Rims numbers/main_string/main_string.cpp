#include "Class_String.h"
#include <iostream>

using namespace std;


int main()
{
    Class_String a;

    // (1)spaces
    //a.Set_str("Aykhan    hello how    are you?");
    //a.Set_str("                                  ");

    // (2)comments // && /**/
    //a.Set_str("Aykhan  /hello how     are you?/");
    //a.Set_str("//Aykhan  /hello how     are you?/");
    //a.compress();
    //a.del_comment();

    // (3)search suffix
    /*a.search_suf("ppapapa", "pa");
    a.show();*/

    // (4)solve summ / dif / ...
    /*a.Set_str("Aykhan 55/5 hello how  60-5   are you?");
    a.show();
    a.solve();
    a.show();*/

    // (5)Rim numbers
    /*a.Set_str("900");
    a.rim_numbers();
    a.show();*/
    
    // (6) fail way
    /*a.Set_str("C:\\Step\\С++lesson_03\\Docs\\Less03.docx");
    a.way_file();*/

    return 0;
}
