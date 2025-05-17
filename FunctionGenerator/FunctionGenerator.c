// Inputs (botões)
#define BT0 PIND.B2
#define BT1 PIND.B3
#define BT2 PIND.B4

// Saídas (display)
#define Data_a  PORTC.B3
#define Data_b  PORTC.B2
#define Data_c  PORTC.B1
#define Data_d  PORTC.B0
#define Data_e  PORTB.B3
#define Data_f  PORTB.B2
#define Data_g  PORTB.B1
#define Data_pd PORTB.B0

// Formas de onda (8 bits)
unsigned char DenteDeSerrabit[] = {
  0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121,
  132, 143, 154, 165, 176, 187, 198, 209, 220, 231, 242, 253
};

unsigned char Triangularbit[] = {
  0, 22, 44, 66, 88, 110, 132, 154, 176, 198, 220, 242,
  220, 198, 176, 154, 132, 110, 88, 66, 44, 22
};

unsigned char Senoidebit[] = {
  127, 160, 191, 217, 237, 250, 250, 255, 250, 237, 217, 191,
  160, 127, 94, 63, 37, 17, 4, 0, 4, 17, 37, 63
};

unsigned char Bits;
signed char cnt;

// Configuração inicial
void configura(void){
  // Entradas dos botões
  DDRD.B2 = 0; PORTD.B2 = 1; // BT0
  DDRD.B3 = 0; PORTD.B3 = 1; // BT1
  DDRD.B4 = 0; PORTD.B4 = 1; // BT2

  // Saídas para display (C: a-d, B: e-g + pd)
  DDRC = 0b00001111;
  DDRB = 0b00001111;
}

// Funções de exibição das formas de onda
void DenteDeSerra(void){
  for(cnt = 0; cnt < 24; cnt++){
    Bits = DenteDeSerrabit[cnt];
    Data_a = Bits.B1;
    Data_b = Bits.B2;
    Data_c = Bits.B3;
    Data_d = Bits.B4;
    Data_e = Bits.B5;
    Data_f = Bits.B6;
    Data_g = Bits.B7;
    Data_pd = Bits.B0;
    delay_ms(3);
  }
}

void Triangular(void){
  for(cnt = 0; cnt < 22; cnt++){
    Bits = Triangularbit[cnt];
    Data_a = Bits.B1;
    Data_b = Bits.B2;
    Data_c = Bits.B3;
    Data_d = Bits.B4;
    Data_e = Bits.B5;
    Data_f = Bits.B6;
    Data_g = Bits.B7;
    Data_pd = Bits.B0;
    delay_ms(3);
  }
}

void Senoide(void){
  for(cnt = 0; cnt < 24; cnt++){
    Bits = Senoidebit[cnt];
    Data_a = Bits.B1;
    Data_b = Bits.B2;
    Data_c = Bits.B3;
    Data_d = Bits.B4;
    Data_e = Bits.B5;
    Data_f = Bits.B6;
    Data_g = Bits.B7;
    Data_pd = Bits.B0;
    delay_ms(3);
  }
}

// Leitura dos botões
void input(void){
  if((BT0) && (!BT1) && (!BT2)){
    DenteDeSerra();
  }
  if((!BT0) && (BT1) && (!BT2)){
    Triangular();
  }
  if((!BT0) && (!BT1) && (BT2)){
    Senoide();
  }
}

// Loop principal
void main() {
  configura();
  while(1){
    input();
  }
}
