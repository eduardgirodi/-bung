#include <stdio.h>
#include <time.h>

struct Messung {
    int spannung;
    float stromstaerke;
    unsigned short druck;
    struct tm zeit;
};

void ausgabe(struct Messung m) {

    printf("Datum: %d.%02d.%02d, Zeit: %02d:%02d:%02d\nSpannung:%d V\nStrom:%.2f A\nDruck: %hu bar\n", m.zeit.tm_year+1900, m.zeit.tm_mon+1, m.zeit.tm_mday, m.zeit.tm_hour, m.zeit.tm_min, m.zeit.tm_sec,
           m.spannung, m.stromstaerke, m.druck);
} 

int main() {
    struct Messung m;
    m.spannung = 220;
    m.stromstaerke = 2.3;
    m.druck = 9;
    time_t t; 
    time(&t); 
    //printf("t: %d\n", t);
    m.zeit = *localtime(&t);

    ausgabe(m);

    return 0;
}


