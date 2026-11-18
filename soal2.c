/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2026/2027
 * Modul               : 3 – Foundation of Algorithm
 * Hari dan Tanggal    : Rabu 18 November 2026
 * Nama (NIM)          : Jonathan Chandra (13224103)
 * Nama File           : Soal2.c
 * Deskripsi           : Mencari tarakan yang diinginkan dengan 2 ukuran gelas
 */


 /**Referensi
  * https://www.geeksforgeeks.org/c/scanf-in-c/
  * https://www.geeksforgeeks.org/dsa/water-jug-problem-complete-tutorial/
  * https://www.tutorialspoint.com/article/water-and-jug-problem-in-cplusplus
  * https://www.geeksforgeeks.org/c/bool-in-c/
  * https://www.w3schools.com/c/c_arrays_multi.php
  * https://www.geeksforgeeks.org/dsa/two-water-jug-puzzle/ 
  */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int minimal(int gelas1, int gelas2, int takaran) {
    if (takaran > gelas1 && takaran > gelas2) {
        return -1; 
    }
    if (takaran == 0) {
        return 0;
    }

    int max_states = (gelas1 + 1) * (gelas2 + 1);
    int gelas[max_states][3];
    bool step[gelas1 + 1][gelas2 + 1];

    for (int i = 0; i <= gelas1; i++) {
        for (int j = 0; j <= gelas2; j++) {
            step[i][j] = false;
        }
    }

    int a = 0;
    int b = 0;

    gelas[b][0] = 0;
    gelas[b][1] = 0;
    gelas[b][2] = 0;
    b++;
    step[0][0] = true;

    int ans = -1;

    while (a != b) {
        int cur1 = gelas[a][0];
        int cur2 = gelas[a][1];
        int langkah = gelas[a][2];
        a++;

        if (cur1 == takaran || cur2 == takaran) {
            ans = langkah;
            break;
        }
        int tuang_1_2;
        int tuang_2_1;
        if(cur1 < (gelas2-cur2)){
            tuang_1_2=cur1;
        }
        else{
            tuang_1_2 = gelas2-cur2;
        }

        if(cur2<(gelas1-cur1)){
            tuang_2_1=cur2;
        }
        else{
            tuang_2_1=gelas1-cur1;
        }


        int next[6][2] = {
            {gelas1, cur2},                         
            {cur1, gelas2},                    
            {0, cur2},                       
            {cur1, 0},                     
            {cur1 - tuang_1_2, cur2 + tuang_1_2}, 
            {cur1 + tuang_2_1, cur2 - tuang_2_1}
        };

        for (int i = 0; i < 6; i++) {
            int n1 = next[i][0];
            int n2 = next[i][1];

            if (!step[n1][n2]) {
                step[n1][n2] = true;
                gelas[b][0] = n1;
                gelas[b][1] = n2;
                gelas[b][2] = langkah + 1;
                b++;
            }
        }
    }

    return ans;
}

int main() {
    int gelas1, gelas2, takaran;
    if (scanf("%d %d %d", &gelas1, &gelas2, &takaran) == 3) {
        int langkah_minimum = minimal(gelas1, gelas2, takaran);
        printf("%d\n", langkah_minimum);
    }
    return 0;
}
