; Funzione fattoriale
; Restituisce in R0 il valore di R1!

;   R0: Risultato
;   R1: Input
;   R2: Contatore
;   R3: Ausiliario input

;   R2 = 1;
;   R0 = 1;
;   while(R2 < R1) {
;       R0 *= R2;
;       R2++;
;   }

#include    "../lib/funzione_moltiplicazione.ixx"

FATTORIALE:     LDWI    R2 1            ; Contatore a 1
                LDWI    R0 1            ; Risultato a 1 (neutro *)
FAT_LOOP:       MV      R1 R3           ; Copio l'input in un registro ausiliario per la sottrazione
                SUB     R2 R3           ; R3 = R3 - R2
                JMPN    FAT_END         ; Se R2 >= R3 (R1), esci
                PUSH    R1              ; Salvo i registri R1, 2, 3
                PUSH    R2
                MV      R0 R1           ; Predispongo R1, R2 per la moltiplicazione
                CALL    MOLTIPLICAZIONE ; Chiamo la funzione
                POP     R2              ; Recupero stack
                POP     R1
                INC     R2              ; Incremento
                JMP     FAT_LOOP        ; Loop
FAT_END:        RET                     ; Fine

; Fine funzione fattoriale