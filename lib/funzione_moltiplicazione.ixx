; Funzione moltiplicazione
; Restituisce in R0 il prodotto di R1 per R2

;   R0 = 0;
;   R3 = 0;
;   while(R3 < R1) {
;       R0 += R1;
;       R3++;
;   }

MOLTIPLICAZIONE:    LDWI    R0 0            ; Inizializzo risultato
                    LDWI    R3 0            ; Inizializzo contatore
MOL_LOOP:           MV      R3 R4           ; Copio contatore per sottrazione
                    SUB     R1 R4           ; Sottraggo (confronto)
                    JMPNN   MOL_END         ; Se R3 >= R1 esci
                    ADD     R2 R0           ; Altrimenti somma R1 ad R0 (salva in R0)
                    INC     R3              ; Incremento contatore
                    JMP     MOL_LOOP        ; Loop
MOL_END:            RET                     ; Fine moltiplicazione


; Fine funzione moltiplicazione