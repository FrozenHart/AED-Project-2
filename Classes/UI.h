#ifndef AED_PROJECT_2_UI_H
#define AED_PROJECT_2_UI_H

#include <iostream>
#include "FileReader.h"
#include "Statistics.h"
#include "Operations.h"
#include <limits>
#include <cstdint>

/**
 * @brief Classe que representa a interface do usuário (UI) para interação com o sistema.
 */
class UI {
public:
    /**
     * @brief Método principal para executar a interface do usuário.
     * @param x Instância de FileReader para acessar os dados do sistema.
     */
    static void run(FileReader x);

    // Métodos para pontos específicos da interface
    static string print_menu();
    static string point1(FileReader x);
    static string point2(FileReader x);
    static string point3(FileReader x);
    static string point4(FileReader x);
    static string point5(FileReader x);
    static string point6(FileReader x);
    static string point7(FileReader x);
    static string point8(FileReader x);
    static string point9(FileReader x);
    static string point10(FileReader x);
    static string point11(FileReader x);
    static string point12(FileReader x);
    static string point13(FileReader x);
    static string point14(FileReader x);
    static string point15(FileReader x);
    static string point16(FileReader x);
    static string point17(FileReader x);

private:
    /**
     * @brief Retorna as informações do aeroporto com o código especificado.
     * @param code Código do aeroporto a ser buscado.
     * @param fileReader Instância de FileReader para acessar os dados do sistema.
     * @return Vetor de strings com as informações do aeroporto correspondente ao código.
     */
    static vector<string> airport(string code, const FileReader& fileReader);

    /**
     * @brief Verifica se existe algum aeroporto com o nome especificado.
     * @param name Nome do aeroporto a ser verificado.
     * @param fileReader Instância de FileReader para acessar os dados do sistema.
     * @return True se existir um aeroporto com o nome especificado, False caso contrário.
     */
    static bool existes_airport_from_name(string name, const FileReader& fileReader);

    /**
     * @brief Obtém o código do aeroporto a partir do nome especificado.
     * @param name Nome do aeroporto do qual deseja-se obter o código.
     * @param fileReader Instância de FileReader para acessar os dados do sistema.
     * @return Código do aeroporto correspondente ao nome especificado.
     */
    static string get_airport_code(string name, const FileReader& fileReader);
};

#endif //AED_PROJECT_2_UI_H
