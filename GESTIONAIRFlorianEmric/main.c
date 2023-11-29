#include <stdio.h>
#include <stdlib.h>

int main()
{
    // exemple d'element struct Passager
    Passager p1 = {"Filloux", "Florian", "07/02/2004",1, 503.65 }
    printf("%c", p1->nom);
    return 0;
}
