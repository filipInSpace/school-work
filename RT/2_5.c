/* Otazka: Vysvetlite koncept rekurzie (môžete si pomôcť s druhým projektom):
    a.	ukážka (netriviálnej) rekurzívnej funkcie príklade z druhého projektu
    b.	korektné vysvetlenie rekurzie a zásobníka volaní/rámec zásobníka volaní */
    
// Odpoved:

int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}


