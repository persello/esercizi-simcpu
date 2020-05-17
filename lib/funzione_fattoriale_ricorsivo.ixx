; Funzione fattoriale
; Restituisce in R0 il valore di R1!

;   R0: Risultato
;   R1: Input (n)
;   R2: Risultato fattoriale ricorsivo
;   R3: Ausiliario input per ricalcolo flag


;   if (n <= 0)
;       return 1;
;   else {
;       return n * fattoriale (n-1);
;   }

#include    "../lib/funzione_moltiplicazione.ixx"

FATTORIALE_RIC:     MV      R1 R3           ; Ricalcolo i flag
                    JMPNZ   FAT_R_ELSE      ; Se n != 0 (> 0) passo all'else, altrimenti continuo qui
                    LDWI    R0 1            ; Carico 1 nel registro R0 (risultato)
                    RET                     ; Esco
FAT_R_ELSE:         PUSH    R1              ; Salvo R1 (n)
                    DEC     R1              ; Decremento per preparazione ricorsione
                    CALL    FATTORIALE_RIC  ; Chiamo ricorsivamente
                    POP     R1              ; Recupero R1 (n, non n - 1)
                    MV      R0 R2           ; Preparo per moltiplicazione tra R1 ed R2
                    CALL    MOLTIPLICAZIONE ; Moltiplico n * fattoriale(n - 1) -> R0
                    RET                     ; Esco