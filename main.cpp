// Caio Toledo
// Igor Butignon

#include <cmath>
#include <iostream>

using namespace std;

// Função para converter as bases de 2 a 8 em decimal.
int BinOctalparaDecimal(string number, int base) {

  int tamanho, result = 0, j = 0;

  tamanho = number.length();

  for (int i = tamanho - 1; i >= 0; i--) {
    result += (number[i] - '0') * pow(base, j);
    j++;
  }

  return result;
}

// Função para converter as bases maiores que 10 em decimal.
int HexaparaDecimal(string hexadecimal, int Base) {

  int decimal = 0;
  int base = 1;

  for (int i = hexadecimal.length() - 1; i >= 0; i--) {

    int digitValue;
    if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9')
      digitValue = hexadecimal[i] - '0';

    else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'Z')
      digitValue = hexadecimal[i] - 'A' + 10;

    else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'z')
      digitValue = hexadecimal[i] - 'a' + 10;

    else {
      // Caractere inválido encontrado
      return -1;
    }

    decimal += digitValue * base;
    base *= Base;
  }

  return decimal;
}

// Função para converter decimal para qualquer outra base.
string DecimalparaQualquer(int number, int Base) {

  string resultado;

  while (number > 0) {

    int resto = number % Base;

    if (resto < 10) {

      resultado =
          char(resto + 48) + resultado; // Converte para caractere e concatena
    }

    else {

      resultado = char(resto + 55) +
                  resultado; // Converte para caractere (A-Z) e concatena
    }

    number /= Base;
  }

  return resultado;
}

int main() {

  // Muitas variáveis.
  int numero_basico, Base;
  int Base_conversao, numero_convertido;
  string vetor_decimal[6];
  string binario, decimal_convertido;
  char status = 'S';

  while (status == 'S' || status == 's') {

    cout << "Base pertencente:\n";
    cout << "Base 2\n";
    cout << "Base 3\n";
    cout << "Base 5\n";
    cout << "Base 8\n";
    cout << "Base 10\n";
    cout << "Base 16\n";
    cin >> Base;

    // Teste Lógico de Bases.
    if ((Base < 2 || Base > 36) || (cin.fail())) {

      system("clear");
      cout << "\nBase inexistente.\n";
      return 0;
    }

    // Se for igual a dez o número digitado será armazenado em uma var int.
    else if (Base == 10) {

      cout << "\nNúmero a ser convertido:\n";
      cin >> numero_basico;

      // T.L. caso o usuário digite algo além de números inteiros.
      if (cin.fail()) {
        system("clear");
        cout << "\nEntrada inválida. \nO valor digitado não faz parte da base 10.\n";
      }
    }

    // Se for diferente será armazenado em uma var string.
    else {

      cout << "\nNúmero a ser convertido:\n";
      cin >> binario;

      // T.L. caso o user digite algo que não faça parte da base selecionada.
      if (Base > 10) {
        for (int i = 0; i < binario.size(); i++) {

          if (!isdigit(binario[i]) && (toupper(binario[i]) < 'A' || toupper(binario[i]) > 'A' + Base - 10)) {

            system("clear");
            cout << "\nNúmero não pertence à base " << Base << endl;
            return 0;
          }
        }
      }

      else if (Base < 10) {
        for (int i = 0; i < binario.size(); i++) {

          if (binario[i] >= '0' + Base) {

            system("clear");
            cout << "\nNúmero não pertence a base " << Base << endl;
            return 0;
          }
        }
      }
    }

    cout << "\nPara qual base converter:\n";
    cout << "Base 2\n";
    cout << "Base 3\n";
    cout << "Base 5\n";
    cout << "Base 8\n";
    cout << "Base 10\n";
    cout << "Base 16\n";
    cout << "Todas (1)\n";
    cin >> Base_conversao;

    // T.L de Bases incongruentes ou inesistentes.
    if (Base_conversao == Base) {

      system("clear");
      cout << "\nVocê escolheu a mesma base, não entendeu que esse programa é um CONVERSOR ??";

    }

    else if (Base_conversao <= 0 || Base_conversao > 36) {

      system("clear");
      cout << "\nBase inexistente.";

    }

    // Se a base para conversão for 10 é só pegar a Base e o valor digitados e
    // converter.
    else if (Base_conversao == 10) {

      if (Base < 10) {
        numero_convertido = BinOctalparaDecimal(binario, Base);
      }

      else
        numero_convertido = HexaparaDecimal(binario, Base);

      system("clear");
      cout << "\nNúmero digitado (Base " << Base << "): " << binario
           << "\nConvertido na base 10: " << numero_convertido;

    }

    else {

      // T.L. de base de conversão, caso a opção 'Todas' seja selecionada.
      if (Base == 10 && Base_conversao == 1) {

        int vetor_bases[] = {2, 3, 5, 8, 10, 16};

        system("clear");
        cout << "\n\n———————\n";

        cout << "Base Original (10): " << numero_basico << "\n\n";

        for (int i = 0; i < 6; i++) {

          vetor_decimal[i] =
              (DecimalparaQualquer(numero_basico, vetor_bases[i]));

          cout << "Base " << vetor_bases[i] << ": " << vetor_decimal[i] << "\n";
        }

        cout << "————————\n";
      }

      // Se a Base for diferente de dez, mais testes lógicos são necessários.
      else if (Base != 10 && Base_conversao == 1) {

        if (Base < 10) { // T.L. para Bases de 2 a 8.

          numero_convertido = BinOctalparaDecimal(binario, Base);

        }

        else if (Base > 10) { // T.L para bases com letras.

          numero_convertido = HexaparaDecimal(binario, Base);
        }

        int vetor_bases[] = {2, 3, 5, 8, 10, 16};

        system("clear");
        cout << "\n\n————————";

        cout << "\nBase Original (" << Base << "): " << binario << endl << endl;

        for (int i = 0; i < 6; i++) {

          vetor_decimal[i] =
              (DecimalparaQualquer(numero_convertido, vetor_bases[i]));

          cout << "Base " << vetor_bases[i] << ": " << vetor_decimal[i] << "\n";
        }

        cout << "————————\n";
      }

      else if (Base == 10) {

        decimal_convertido = DecimalparaQualquer(numero_basico, Base_conversao);

        system("clear");
        cout << "\nNúmero digitado (Base " << Base << "): " << numero_basico
             << "\nConvertido na base " << Base_conversao << ": "
             << decimal_convertido;

      }

      /*Se a Base for diferente de dez
      será necessário converter para
      decimal e depois para a base de
      conversão desejada.*/
      else if (Base < 10) {

        numero_convertido = BinOctalparaDecimal(binario, Base);

        decimal_convertido =
            DecimalparaQualquer(numero_convertido, Base_conversao);

        system("clear");
        cout << "\nNúmero digitado (Base " << Base << "): " << binario
             << "\nConvertido na base " << Base_conversao << ": "
             << decimal_convertido;

      }

      else if (Base > 10) {

        numero_convertido = HexaparaDecimal(binario, Base);

        decimal_convertido =
            DecimalparaQualquer(numero_convertido, Base_conversao);

        system("clear");
        cout << "\nNúmero digitado (Base " << Base << "): " << binario
             << "\nConvertido na base " << Base_conversao << ": "
             << decimal_convertido;
      }
    }

    // Fim do loop While
    // Pergunta ao user se ele deseja fazer mais conversões.
    cout << "\n\nProseguir(S/N)? ";
    cin >> status;
    cout << endl << endl;

    if (status == 'S' || status == 's') {
      system("clear");
    }
  }

  cout << "Até logo !";

  return 0;
}
