#ifndef FUNCAORPG_H_INCLUDED
#define FUNCAORPG_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream> //ofstream , ifstream , fstream
#include <locale.h>
#include <sstream>
#include <string>
#include <time.h>

using namespace std;

int menu(){///MENU
    int verif=0;
    int escolha;

    while(verif==0){

        system("color 4b");

        string menu;
        ifstream menu_arquivo;
        menu_arquivo.open("./dialogos/menu.txt");

        while(menu_arquivo.eof()==false) {
            getline(menu_arquivo, menu);
            Sleep(50);
            cout<<menu<<endl;
        }
        cin>>escolha;

        if(escolha==1 or escolha == 2 or escolha == 3){
            verif++;
        }
        system("cls");
    }

    system ("cls");
    return escolha;

}

void creditos(){///CREDITOS

    int digit=0;

    system("color 00");

    system("cls");
    char credito;

    ifstream credito_arquivo;
    credito_arquivo.open("./dialogos/creditos.txt");

    while(credito_arquivo.eof()==false){
        credito = credito_arquivo.get();
        Sleep(5);
        cout<<credito;

    }
    cout<<"\n";
    while(digit!=1){
        cout<<"Digite 1 para voltar.";
        cin>>digit;
    }


    system("cls");

}

struct equipamento{///EQUIPAMENTOS
    int espada, armadura, anel, bota, escudo, dinheiro, chave;

};

struct player{///STRUCT DO PLAYER

    int forca, agil, def, hp, intelig;
    string nome;
    string slots[2];
    int classe;

};

player classe(player &p1, int opcao, equipamento &e1){///CLASSE DO JOGADOR

    e1.espada = 0;
    e1.anel = 0;
    e1.armadura = 0;
    e1.bota = 0;
    e1.dinheiro = 0;
    e1.escudo = 0;
    e1.chave = 0;

    switch(opcao){

        case 1://Guerreiro
            p1.forca = 6;
            p1.agil = 5;
            p1.def = 6;
            p1.hp= 20;
            p1.intelig = 2;

            return p1;
        break;
        case 2://MAGO

            p1.forca = 2;
            p1.agil = 3;
            p1.def = 3;
            p1.hp= 20;
            p1.intelig = 6;

            return p1;
        break;
        case 3://LADINO

            p1.forca = 4;
            p1.agil = 7;
            p1.def = 4;
            p1.hp= 20;
            p1.intelig = 2;

            return p1;
        break;
    }

}

struct inimigo{///STRUCT DO INIMIGO
    int forca, def, hp;

};

inimigo stats(inimigo &i1, int opcao){///STATUS DO INIMIGO

    switch(opcao){
        case 1:///GOBLIN
            i1.forca = 3;
            i1.def = 5;
            i1.hp = 20;

        break;
        case 2:///GUARDA
            i1.forca = 4;
            i1.def = 6;
            i1.hp = 30;

        break;
        case 3:///DONO DO CASTELO
            i1.forca = 7;
            i1.def = 7;
            i1.hp = 35;

        break;
        case 4:///BARÃO
            i1.forca = 7;
            i1.def = 7;
            i1.hp = 35;

        break;
    }


}

void telademorte(){///FIM DE JOGO

    cout<<"\n\n\n\n\n\n";
    cout<<"                                                     VOCE MORREU";
    cout<<"\n\n\n\n\n\n";
    system("pause");
}

int atkplayer(player p1,equipamento e1){///ATAQUE DO PLAYER
    int playerhit;
    srand(time(NULL));
    switch(p1.classe){

        case 1://Guerreiro
            playerhit=(rand()%3)*(p1.forca+e1.espada);
            cout<<"Você da: "<<playerhit<<" de dano!"<<endl;
            return playerhit;
        break;
        case 2://Mago
            playerhit=(rand()%3)*(p1.intelig+e1.anel);
            cout<<"Você da: "<<playerhit<<" de dano!"<<endl;
            return playerhit;
        break;
        case 3://Ladino
            playerhit=(rand()%3)*(p1.agil+e1.bota);
            cout<<"Você da: "<<playerhit<<" de dano!"<<endl;
            return playerhit;
        break;

    }
}

int atkinimigo(inimigo &i1,int opcao,equipamento e1){///ATAQUE DO INIMIGO
    int inimigohit;
    srand(time(NULL));
    //stats(i1,opcao);
    switch(opcao){
        case 1://GOBLIN
            inimigohit=(rand()%3+1)+(i1.forca-e1.armadura);
            cout<<"O goblin te deu: "<<inimigohit<<" de dano\n";
            return inimigohit;
        break;
        case 2://GUARDA
            inimigohit=(rand()%12+5)+(i1.forca-e1.armadura);
            cout<<"O guarda te deu: "<<inimigohit<<" de dano\n";
            return inimigohit;
        break;
        case 3://DONO DO CASTELO
            inimigohit=(rand()%15+5)+(i1.forca-e1.armadura);
            cout<<"O dono do castelo te deu: "<<inimigohit<<" de dano\n";
            return inimigohit;
        break;
        case 4://BARAO
            inimigohit=(rand()%15+5)+(i1.forca-e1.armadura);
            cout<<"O barao te deu: "<<inimigohit<<" de dano\n";
            return inimigohit;
        break;
    }
}

int combate(player &p1,int opcao,inimigo &i1,equipamento e1){ ///COMBATE

    stats(i1,opcao);
    int playerhit;
    int inimigohit;
    int opcaoinimigo=0;

    cout<<"Você encontrou um Inimigo."<<endl;

    while(p1.hp>0 && i1.hp>0){


            cout<<"Oque deseja fazer?:\n\n\n"<<endl;
            cout<<"                     [1]ATACAR                     [2]FUGIR\n\n\n";
            cin>>opcaoinimigo;
            if(opcaoinimigo!= 1 && opcaoinimigo !=2){
                cout<<"Opção indisponivel";
                system("cls");
                cout<<"Você encontrou um Inimigo."<<endl;

                cout<<"Oque deseja fazer?:\n\n\n"<<endl;
                cout<<"                     [1]ATACAR                     [2]FUGIR\n\n\n";
                cin>>opcaoinimigo;
                system("cls");
            }
            if(opcaoinimigo==2){///CASO O JOGADOR ESCOLHA FUGIR
                system("cls");
                srand(time(NULL));
                int fuga=rand()%10+1;
                if(fuga>=8){//SE FOR MAIS QUE 7 ELE CONSEGUE
                    return 2;
                }else{//SE NAO ELE MORRE

                cout<<"Você tenta fugir, porem o inimigo te alcança e te mata. não corra de suas batalhas!";

                return 0;
                }
            }else if(opcaoinimigo==1){///COMBATE
                system("pause");
                system("cls");

                switch(p1.classe){

                    case 1:
                        //GUERREIRO
                        cout<<"Você empunha sua espada e ataca o inimigo na sua frente!"<<endl;
                    break;
                    case 2:
                        //MAGO
                        cout<<"Você usa as artes arcanas e conjura uma magia no inimigo a sua frente!"<<endl;
                    break;
                    case 3:
                        //LADINO
                        cout<<"Você pega sua adaga e corre para atacar o inimigo na sua frente!"<<endl;
                    break;
                }
                playerhit = atkplayer(p1,e1);


                if(playerhit==0){
                    cout<<"Você errou o ataque!\n"<<endl;

                    cout<<"O inimigo veio te atacar!"<<endl;
                    inimigohit = atkinimigo(i1, opcao, e1);
                    if(inimigohit==0){
                        cout<<"Ele errou o ataque!"<<endl;
                    }else{
                        cout<<"Você tomou o ataque!"<<endl;
                        p1.hp = p1.hp - inimigohit;

                        if(p1.hp<0){
                            cout<<"Você não tem mais pontos de vida. :("<<endl;
                            system("pause");
                            system("cls");
                            return 0;
                        }else{
                        cout<<"\nVocê ainda tem "<<p1.hp<<" pontos de vida!\n";
                        system("pause");
                        system("cls");
                        }
                    }
                }else{
                    cout<<"Você acertou o ataque!\n"<<endl;
                    i1.hp = i1.hp - playerhit;

                    if(i1.hp<0){
                        system("pause");
                        return 1;
                    }

                    cout<<"O inimigo veio te atacar!"<<endl;
                    inimigohit = atkinimigo(i1, opcao, e1);
                    if(inimigohit==0){
                        cout<<"Ele errou o ataque!"<<endl;
                    }else{
                        cout<<"Você tomou o ataque!"<<endl;
                        p1.hp = p1.hp - inimigohit;

                        if(p1.hp<=0){
                            cout<<"Você não tem mais pontos de vida. :("<<endl;
                            system("pause");
                            system("cls");
                            return 0;
                        }else{
                        cout<<"\nVocê ainda tem "<<p1.hp<<" pontos de vida!\n";
                        system("pause");
                        system("cls");
                        }
                    }
                }

            }else{
                cout<<"Opção indisponivel";
            }

            if(i1.hp<0){
                        return 1;
                    }

    }


}

int taverna(player &p1,equipamento &e1) { ///TAVERNA
    int opcao;
    string taverna;
    ifstream taverna_arquivo;
    taverna_arquivo.open("./dialogos/taverna.txt");

    system("cls");
    system("color 07");

    while(opcao != 1){//enquanto a opção nao for 1 ele continua na taverna

        while(taverna_arquivo.eof() == false) {
            taverna = taverna_arquivo.get();
            Sleep(1);
            cout<<taverna;
        }

        cout<<"\n\n";
        cin>>opcao;

        taverna_arquivo.close();

        if(opcao == 2){ //se a opção for 2 ele toma cerveja
            string cerveja;
            ifstream cerveja_arquivo;
            cerveja_arquivo.open("./dialogos/cerveja.txt");

            system("cls");
            if(p1.agil>0){
                while(cerveja_arquivo.eof() == false){
                    cerveja = cerveja_arquivo.get();
                    Sleep(1);
                    cout<<cerveja;
                }
                p1.agil -= 2;
            }else{
                char morreu_cerveja;
                ifstream morreu_cerveja_arquivo;
                morreu_cerveja_arquivo.open("./dialogos/morreu_cerveja.txt");
                system("cls");
                while(morreu_cerveja != '.'){
                    morreu_cerveja = morreu_cerveja_arquivo.get();
                    Sleep(1);
                    cout<<morreu_cerveja;
                }
                telademorte();
                return 0;
            }
        }
    }
    e1.dinheiro+=15;

}

int ferreiro(equipamento &e1){ ///FERREIRO

    int opcao;
    system("cls");
    system("color 07");

    while(opcao!=5){
        char ferreiro;
        ifstream ferreiro_arquivo;
        ferreiro_arquivo.open("./dialogos/ferreiro.txt");
        while(ferreiro_arquivo.eof() == false) {
            ferreiro = ferreiro_arquivo.get();
            Sleep(1);
            cout<<ferreiro;
        }

        cout<<"\n\n";
        cin>>opcao;


        ferreiro_arquivo.close();
        int simounao;
        simounao=0;


        system("cls");
        if(e1.dinheiro>0){
            switch(opcao){
                case 1://ESPADA
                    cout<<"Você quer comprar a espada por 5 de ouro? [sim = 1|nao = 2]\n"<<endl;
                    cin>>simounao;

                    if(simounao==1){
                        e1.dinheiro-=5;
                        cout<<"Espada comprada!\n-5 de ouro\n"<<"Você tem "<<e1.dinheiro<<" moedas."<<endl;
                        e1.espada=2;
                        system("pause");
                        system("cls");
                        return 1;
                    }else{
                        return 1;
                    }
                break;
                case 2://ARMADURA
                    cout<<"Você quer comprar a armadura por 10 de ouro? [sim = 1|nao = 2]\n"<<endl;
                    cin>>simounao;
                    if(simounao==1){
                        e1.dinheiro-=10;
                        cout<<"Armadura comprada!\n-10 de ouro\n"<<"Você tem "<<e1.dinheiro<<" moedas."<<endl;
                        e1.armadura=3;
                        system("pause");
                        system("cls");
                        return 1;
                    }else{
                        return 1;
                    }

                break;
                case 3://ANEL MAGICO
                    cout<<"Você quer comprar o anel mágico por 5 de ouro? [sim = 1|nao = 2]\n"<<endl;
                    cin>>simounao;

                    if(simounao==1){
                        e1.dinheiro-=5;
                        cout<<"Anel mágico comprado!\n-5 de ouro\n"<<"Você tem "<<e1.dinheiro<<" moedas."<<endl;
                        e1.anel=2;
                        system("pause");
                        system("cls");
                        return 1;
                    }else{
                        return 1;
                    }
                break;
                case 4://BOTAS
                    cout<<"Você quer comprar as botas por 5 de ouro? [sim = 1|nao = 2]\n"<<endl;
                    cin>>simounao;

                    if(simounao==1){
                        e1.dinheiro-=5;
                        cout<<"Botas compradas!\n-5 de ouro\n"<<"Você tem "<<e1.dinheiro<<" moedas."<<endl;
                        e1.bota=2;
                        system("pause");
                        system("cls");
                        return 1;
                    }else{
                        return 1;
                    }
                break;
                case 5://VOLTAR
                    return 0;
                break;
                default:
                    cout<<"Opção indisponivel"<<endl;
                break;
            }
        }else{
            if(opcao==5){
                return 0;
            }else{
                cout<<"\nVocê não tem mais dinheiro amigo.\n"<<endl;
            }

        }
    }
}

int lojaarma(equipamento &e1){ ///LOJA DE ARMAS

    int opcao;

    while(opcao!=2){
        string loja_arma;
        ifstream loja_arma_arquivo;
        loja_arma_arquivo.open("./dialogos/loja_arma.txt");

        while(loja_arma_arquivo.eof() == false) {
            loja_arma = loja_arma_arquivo.get();
            Sleep(1);
            cout<<loja_arma;
        }

        cout<<"\n\n";
        cin>>opcao;

        if(opcao==1){
            while(ferreiro(e1)==1){
                ferreiro(e1);
            }
        }else if(opcao==2){
            return 0;
        }else{
            system("cls");
            cout<<"Opção invalida"<<endl;
        }

    }
}

int cidade(equipamento &e1){ ///CIDADE

    int opcao2;
    int opcao;

        while(opcao!=2){

            system("cls");
            system("color 07");

            string cidade;
            ifstream cidade_arquivo;
            cidade_arquivo.open("./dialogos/cidade.txt");

            while(cidade_arquivo.eof() == false) {
                cidade = cidade_arquivo.get();
                Sleep(1);
                cout<<cidade;
            }

            cout<<"\n\n";
            cin>>opcao;

            cidade_arquivo.close();

            if(opcao==1){

                system("cls");
                system("color 07");
                if(lojaarma(e1)==1){

                }


            }else{
            system("cls");

            return 1;
            }
        }
}

int casaAbandonada(equipamento &e1){///CASA

    int opcao=0;


    system("cls");
    string casa;
    ifstream casa_arquivo;
    casa_arquivo.open("./dialogos/casa.txt");

    while(casa_arquivo.eof() == false) {
        casa = casa_arquivo.get();
        Sleep(1);
        cout<<casa;
    }
    cin>>opcao;

    if(opcao != 1 && opcao != 2){
        cout<<"Opção Invalida"<<endl;
    } else if(opcao == 1) {
        e1.chave = 1;
        e1.espada = 3;
        e1.anel = 4;
        e1.bota = 5;
        e1.dinheiro += 10;
        return 1;
    } else {
        return 1;
    }

}

int GanhouGoblin(equipamento &e1, player &p1){///GANHOU DO GOBLIN
    int opcao;

        system("cls");
        system("color 02");

        string ganhou_goblin;
        ifstream ganhou_goblin_arquivo;
        ganhou_goblin_arquivo.open("./dialogos/ganhou_goblin.txt");

        while(ganhou_goblin_arquivo.eof() == false) {
            ganhou_goblin = ganhou_goblin_arquivo.get();
            Sleep(1);
            cout<<ganhou_goblin;
        }

        cout<<"\n\n";
        cin>>opcao;

        ganhou_goblin_arquivo.close();

        return opcao;

}

int floresta(equipamento &e1,player &p1,inimigo &i1){///FLORESTA
    int opcao=0;

        system("cls");
        system("color 02");

        while(opcao != 1 && opcao != 2){//1 goblin 2 casa

        string floresta;
        ifstream floresta_arquivo;
        floresta_arquivo.open("./dialogos/floresta.txt");

        while(floresta_arquivo.eof() == false) {
            floresta = floresta_arquivo.get();
            Sleep(1);
            cout<<floresta;
        }

        cout<<"\n\n"<<endl;
        cin>>opcao;

        if(opcao != 1 && opcao != 2){
            cout<<"opcao indisponivel"<<endl;
        }
        return opcao;
        }

}

int combateGoblin(player &p1, equipamento &e1, inimigo &i1){///COMBATE DO GOBLIN

    int rescombat;

        string combate_goblin;
        ifstream combate_goblin_arquivo;
        combate_goblin_arquivo.open("./dialogos/combate_goblin.txt");

        while(combate_goblin_arquivo.eof() == false) {
            combate_goblin = combate_goblin_arquivo.get();
            Sleep(1);
            cout<<combate_goblin;
        }

        cout<<"\n\n";

        combate_goblin_arquivo.close();

        ///ESSA PARTE DO CODIGO É ONDE SE CHAMA A FUNÇÃO COMBATE  !!!!
        //////////////////////////////////////////////////////////////
         stats(i1,1);
        int armazenamentocombate;
        armazenamentocombate=combate(p1,1,i1,e1);
        if(armazenamentocombate==2){///caso consiga fugir
            rescombat=2;
        }else if(armazenamentocombate==1){///caso derrote o inimigo
            rescombat=1;
        }else{///caso morra
            telademorte();
            return 0;
        }
        //////////////////////////////////////////////////////////////

        if(rescombat==1){
            int ganhouGoblin=0;


            while(ganhouGoblin != 1){
                ganhouGoblin = GanhouGoblin(e1,p1);
                if(ganhouGoblin != 1){
                system("cls");

                string tenta_voltar;
                ifstream tenta_voltar_arquivo;
                tenta_voltar_arquivo.open("./dialogos/volta_cidade.txt");

                while(tenta_voltar_arquivo.eof() == false) {
                    tenta_voltar = tenta_voltar_arquivo.get();
                    Sleep(1);
                    cout<<tenta_voltar;
                }

                system("pause");

                }
            }
        }else{
            system("cls");
            cout<<"Voce correu muito rapido e conseguiu fugir!\n"<<endl;

            string tenta_voltar;
            ifstream tenta_voltar_arquivo;
            tenta_voltar_arquivo.open("./dialogos/volta_cidade.txt");

            while(tenta_voltar_arquivo.eof() == false) {
                tenta_voltar = tenta_voltar_arquivo.get();
                Sleep(1);
                cout<<tenta_voltar;
            }
            system("pause");
        }

    return 1;

}

int escadaria(equipamento &e1){///ESCADAS

    int escolha;

        string escada_foi_preso;
        ifstream escada_foi_preso_arquivo;
        escada_foi_preso_arquivo.open("./dialogos/escada_foi_preso.txt");

        system("cls");

        while(escada_foi_preso_arquivo.eof()==false) {
            escada_foi_preso = escada_foi_preso_arquivo.get();
            Sleep(1);
            cout<<escada_foi_preso;
        }
        cout<<"\n\n";
        cin>>escolha;
        return escolha;

}

int combateGuarda(player &p1, equipamento &e1, inimigo &i1){///COMBATE DO GUARDA

    int rescombat;

    ///ESSA PARTE DO CODIGO É ONDE SE CHAMA A FUNÇÃO COMBATE  !!!!
    //////////////////////////////////////////////////////////////
    stats(i1,2);
    int armazenamentocombate;
    armazenamentocombate=combate(p1,2,i1,e1);
    if(armazenamentocombate==2){///caso consiga fugir
        rescombat=2;
    }else if(armazenamentocombate==1){///caso derrote o inimigo
        rescombat=1;
    }else{///caso morra ///QUANDO ELE FOGE DO GUARDA NAO APARECE A TELA DE VOCE MORREU -------------------------------------------------
        telademorte();
        return 0;
    }
    //////////////////////////////////////////////////////////////
    system("cls");
    if(rescombat==2){
        cout<<"Você está no territorio inimigo, não pode fugir aqui!\n";
    }else{
        string mata_guarda;
        ifstream mata_guarda_arquivo;
        mata_guarda_arquivo.open("./dialogos/mata_guarda.txt");

        while(mata_guarda_arquivo.eof() == false) {
            mata_guarda = mata_guarda_arquivo.get();
            Sleep(1);
            cout<<mata_guarda;
        }

        cout<<"\n\n";

        mata_guarda_arquivo.close();

    }



}

int salaoCastelo () {///SALAO DO CASTELO
    int escolha, escolhaSalao;

    while(escolhaSalao != 1){
        string salao_castelo;
        ifstream salao_castelo_arquivo;
        salao_castelo_arquivo.open("./dialogos/salao_castelo.txt");

        system("cls");

        while(salao_castelo_arquivo.eof()==false) {
            salao_castelo = salao_castelo_arquivo.get();
            Sleep(1);
            cout<<salao_castelo;
        }
        cout<<"\n\n";
        cin>>escolha;//1 verifica porta 2 sobe escada

        if(escolha == 1) {

        string encontra_quarto_salao;
        ifstream encontra_quarto_salao_arquivo;
        encontra_quarto_salao_arquivo.open("./dialogos/encontra_quarto_salao.txt");

        system("cls");

        while(encontra_quarto_salao_arquivo.eof()==false) {
            encontra_quarto_salao = encontra_quarto_salao_arquivo.get();
            Sleep(1);
            cout<<encontra_quarto_salao;
        }
        cout<<"\n\n";
        cin>>escolhaSalao;

        } else {

            return 1;

        }
        string entra_quarto_salao;
        ifstream entra_quarto_salao_arquivo;
        entra_quarto_salao_arquivo.open("./dialogos/entra_quarto_salao.txt");

        system("cls");

        while(entra_quarto_salao_arquivo.eof()==false) {
            entra_quarto_salao = entra_quarto_salao_arquivo.get();
            Sleep(1);
            cout<<entra_quarto_salao;
        }
        cout<<"\n\n\n";
        system("pause");

    }
    return 1;

}

int castelo(){///CASTELO
    system("color 0e");

    int escolha;
    string seguir_pegada;
    ifstream seguir_pegada_arquivo;
    seguir_pegada_arquivo.open("./dialogos/seguir_pegada.txt");

    system("cls");

    while(seguir_pegada_arquivo.eof()==false) {
        seguir_pegada = seguir_pegada_arquivo.get();
        Sleep(1);
        cout<<seguir_pegada;
    }
    cout<<"\n\n";
    cin>>escolha;

    if(escolha == 1){
        if(salaoCastelo()==1){
            return 1;
        }
    } else {
        return 0;
    }

}

int subornar(equipamento &e1){///SUBORNO DO GUARDA
    if(e1.dinheiro<15){

        string suborno_guarda_nao_consegue;
        ifstream suborno_guarda_nao_consegue_arquivo;
        suborno_guarda_nao_consegue_arquivo.open("./dialogos/suborno_guarda_nao_consegue.txt");

        while(suborno_guarda_nao_consegue_arquivo.eof() == false) {
            suborno_guarda_nao_consegue = suborno_guarda_nao_consegue_arquivo.get();
            Sleep(1);
            cout<<suborno_guarda_nao_consegue;
        }

        suborno_guarda_nao_consegue_arquivo.close();
        system("pause");
        return 0;
    }else{
        string suborno_guarda_consegue;
        ifstream suborno_guarda_consegue_arquivo;
        suborno_guarda_consegue_arquivo.open("./dialogos/suborno_guarda_consegue.txt");

        while(suborno_guarda_consegue_arquivo.eof() == false) {
            suborno_guarda_consegue = suborno_guarda_consegue_arquivo.get();
            Sleep(1);
            cout<<suborno_guarda_consegue;
        }

        suborno_guarda_consegue_arquivo.close();
        cout<<"\n\n";
        system("pause");
        return 1;
    }
}

int tentaroubar(player &p1){
    int roubo;
    roubo=(rand()%10+1)+(p1.agil);

    if(roubo >= 10){
        string consegue_roubar_guarda;
        ifstream consegue_roubar_guarda_arquivo;
        consegue_roubar_guarda_arquivo.open("./dialogos/consegue_roubar_guarda.txt");

        system("cls");
        system("color 07");

        while(consegue_roubar_guarda_arquivo.eof() == false) {
            consegue_roubar_guarda = consegue_roubar_guarda_arquivo.get();
            Sleep(1);
            cout<<consegue_roubar_guarda;
        }

        system("pause");
        return 1;

    } else {

        string nao_consegue_roubar_guarda;
        ifstream nao_consegue_roubar_guarda_arquivo;
        nao_consegue_roubar_guarda_arquivo.open("./dialogos/nao_consegue_roubar_guarda.txt");

        system("cls");
        system("color 07");



        while(nao_consegue_roubar_guarda_arquivo.eof() == false) {
            nao_consegue_roubar_guarda = nao_consegue_roubar_guarda_arquivo.get();
            Sleep(1);
            cout<<nao_consegue_roubar_guarda;
        }
        return 0;
    }
}

int combateMisol(player &p1, equipamento &e1, inimigo &i1){///COMBATE MISOL
    system("color 04");
    int rescombat;

    ///ESSA PARTE DO CODIGO É ONDE SE CHAMA A FUNÇÃO COMBATE  !!!!
    //////////////////////////////////////////////////////////////
    stats(i1,3);
    int armazenamentocombate;
    armazenamentocombate=combate(p1,3,i1,e1);
    if(armazenamentocombate==2){///caso consiga fugir
        rescombat=2;
    }else if(armazenamentocombate==1){///caso derrote o inimigo
        rescombat=1;
    }else{
        telademorte();
        return 0;
    }
    //////////////////////////////////////////////////////////////
    system("cls");
    if(rescombat==2){
        system("cls");
        cout<<"Você tenta fugir, então Misol chama seus guardas para lhe prenderem. Misol começa a rir de você, e solta a frase: executem-no, um covarde não merece viver!\n";
        telademorte();
        system("pause");
        return 0;
    }

}

int combateBarao(player &p1, equipamento &e1, inimigo &i1){///COMBATE MISOL
    system("color 09");
    int rescombat;

    ///ESSA PARTE DO CODIGO É ONDE SE CHAMA A FUNÇÃO COMBATE  !!!!
    //////////////////////////////////////////////////////////////
    stats(i1,4);
    int armazenamentocombate;
    armazenamentocombate=combate(p1,4,i1,e1);
    if(armazenamentocombate==2){///caso consiga fugir
        rescombat=2;
    }else if(armazenamentocombate==1){///caso derrote o inimigo
        rescombat=1;
    }else{
        telademorte();
        return 0;
    }
    //////////////////////////////////////////////////////////////
    system("cls");
    if(rescombat==2){
        system("cls");
        cout<<"Você tenta fugir, então o Barão usa uma magia que lhe paraliza, então ele da uma facada em seu peito, oque o mata instantaneamente!\n";
        telademorte();
        system("pause");
        return 0;
    }else{
        return 1;
    }

}

void telafim(){
    string telafim;
    ifstream telafim_arquivo;
    telafim_arquivo.open("./dialogos/telafim.txt");

    system("cls");

    while(telafim_arquivo.eof()==false) {
        telafim = telafim_arquivo.get();
        Sleep(1);
        cout<<telafim;
    }
    cout<<"\n\n";
    telafim_arquivo.close();
    system("pause");
    system("cls");
}

int final1(){
    string mata_misol;
    ifstream mata_misol_arquivo;
    mata_misol_arquivo.open("./dialogos/mata_misol.txt");

    system("cls");

    while(mata_misol_arquivo.eof()==false) {
        mata_misol = mata_misol_arquivo.get();
        Sleep(1);
        cout<<mata_misol;
    }
    cout<<"\n\n";
    mata_misol_arquivo.close();
    system("pause");
    system("cls");

    telafim();

    return 0;

}

int final2(){
    string mata_barao;
    ifstream mata_barao_arquivo;
    mata_barao_arquivo.open("./dialogos/mata_barao.txt");

    system("cls");

    while(mata_barao_arquivo.eof()==false) {
        mata_barao = mata_barao_arquivo.get();
        Sleep(1);
        cout<<mata_barao;
    }
    cout<<"\n\n";
    mata_barao_arquivo.close();
    system("pause");
    ShellExecute(NULL, "open", "https://www.youtube.com/watch?v=oHg5SJYRHA0", NULL, NULL, SW_SHOWNORMAL);
    system("cls");

    telafim();

    return 0;

}

int saladotrono(player &p1,equipamento &e1,inimigo &i1){
    string castelo_de_novo;
    ifstream castelo_de_novo_arquivo;
    castelo_de_novo_arquivo.open("./dialogos/castelo_de_novo.txt");

    system("cls");

    while(castelo_de_novo_arquivo.eof()==false) {
        castelo_de_novo = castelo_de_novo_arquivo.get();
        Sleep(1);
        cout<<castelo_de_novo;
    }
    cout<<"\n\n";
    system("pause");
    castelo_de_novo_arquivo.close();
    system("cls");

    if(e1.chave==0){
        string misolnokey;
        ifstream misolnokey_arquivo;
        misolnokey_arquivo.open("./dialogos/misolnokey.txt");

        system("cls");

        while(misolnokey_arquivo.eof()==false) {
            misolnokey = misolnokey_arquivo.get();
            Sleep(1);
            cout<<misolnokey;
        }
        cout<<"\n\n";
        system("pause");
        misolnokey_arquivo.close();
        system("cls");

        return 0;



    }else{
        string misolwithkey;
        ifstream misolwithkey_arquivo;
        misolwithkey_arquivo.open("./dialogos/misolwithkey.txt");

        system("cls");

        while(misolwithkey_arquivo.eof()==false) {
            misolwithkey = misolwithkey_arquivo.get();
            Sleep(1);
            cout<<misolwithkey;
        }
        cout<<"\n\n";
        misolwithkey_arquivo.close();

        return 1;


    }

}

void encontrabarao(){
    string encontra_barao;
    ifstream encontra_barao_arquivo;
    encontra_barao_arquivo.open("./dialogos/encontra_barao.txt");

    system("cls");

    while(encontra_barao_arquivo.eof()==false) {
        encontra_barao = encontra_barao_arquivo.get();
        Sleep(1);
        cout<<encontra_barao;
    }
    cout<<"\n\n";
    encontra_barao_arquivo.close();
    system("pause");
    system("cls");

}

int finalcomchave(){
    int opcao;
    cout<<"\n";
    cin>>opcao;

    if(opcao==2){
        return 0;
    }else{
        return 1;
    }


}





#endif // FUNCAORPG_H_INCLUDED
