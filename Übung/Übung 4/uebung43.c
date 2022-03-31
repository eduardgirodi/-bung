#include <stdio.h>
#include <time.h>

typedef struct messung
{
    int spannung;
    double stromstaerke;
    unsigned short druck;
    struct tm zeit;
} Messung;

void ausgabe(Messung m)
{
    printf("Datum: %02d.%02d.%d, Zeit: %02d:%02d:%02d\n", m.zeit.tm_mday, m.zeit.tm_mon+1, m.zeit.tm_year+1900, m.zeit.tm_hour, m.zeit.tm_min, m.zeit.tm_sec);
    printf("Spannung: %d V\n",m.spannung);
    printf("Stromstaerke: %.2lf A\n", m.stromstaerke);
    printf("Druck: %d Bar\n", m.druck);
}

int main()
{
    Messung m;
    printf("Spannung (-250 V bis 250 V): ");
    scanf("%d", &m.spannung);
    printf("Stromstaerke (-10.0 A bis 10.0 A): ");
    scanf("%lf", &m.stromstaerke);
    printf("Druck (0 Bar bis 10 Bar): ");
    scanf("%hu", &m.druck);
    time_t t;
    time(&t);
    m.zeit = *localtime(&t);
    ausgabe(m);
    return 0;
}