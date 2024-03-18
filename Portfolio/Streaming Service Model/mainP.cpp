/*
Jocelyn Ileana Balderas Sánchez-A01798528
Andrea Doce Murillo-A01799931

Proyecto Final



#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>


using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Pelicula.hpp"
#include "Serie.hpp"
#include "PlataformaStreaming.hpp"
#include "Video.hpp"

using namespace std;

int main()
{
    PlataformaStreaming n1;
    n1.leerArchivo();
    n1.iniciar();
}

*/

/*
Jocelyn Ileana Balderas Sánchez-A01798528
Andrea Doce Murillo-A01799931

Proyecto Final

*/

#include "Video.hpp"

// EJEMPLO

#include <iostream>
#include "Video.h"
#include "Pelicula.h"
#include "Series.h"
#include "Episodio.h"
#include <fstream>
#include <vector>

using namespace std;
int main()
{

    // Creating different movie objects and adding them to an array

    // movie LordOfTheRings(0, "Lord of the Rings", 155, "Adventure", 5);
    // movie StarWars(1, "Star Wars", 132, "SciFi", 5);

    // movie moviearr[5] = {LordOfTheRings, StarWars, Inception, Interstellar, Tenet};
    // id, titulo, tipo, duracion, genero, año, estudio, nacionalidad, director, personajes, actores
    Pelicula Bodas27(0, "27 Bodas", 1.51, "Romance", 2008, "20thCenturyFox", "Estados Unidos", "Anne Fletcher", "Jane-Kevin-Tess-George-Casey", "Katherine-James-Malin-Edward-Judy");
    Pelicula ElDescanso(1, "El descanso", 2.18, "Romance", 2006, "Universal Pictures", "Estados Unidos", "Nancy Meyers", "Graham-Amanda-Iris-Miles-Jasper", "Jude-Cameron-Kate-Jack-Rufus");
    Pelicula UnaEsposaDeMentira(2, "Una esposa de mentira", 1.57, "Comedia", 2011, "ColumbiaPictures", "Estados Unidos", "Dennis Dugan", "Daniel-Katherine-Palmer-Maggie-Devlin", "Adam-Jennifer-Brooklyn-Bailee-Nicole");
    Pelicula YDondeEstanLasRubias(3, "Y donde estan las rubias?", 1.49, "Comedia", 2004, "ColumbiaPictures", "Estados Unidos", "Keenen Ivory Wayans", "Marcus-Kevin-Latrell-Karen-Heather", "Marlon-Shawn-Terry-Busy-Jaime");
    Pelicula RapidosYFuriosos10(4, "Rapidos y furiosos 10", 2.21, "Accion", 2023, "UniversalPictures", "Estados Unidos", "Louis Leterrier", "Dominic-Dante-Aimes-AbuelitaToretto-Letty", "Vin-Jason-Alan-Rita-Michelle");
    Pelicula MisionImposible7(5, "Mision Imposible 7", 2.43, "Accion", 2023, "ParamountPictures", "Estados Unidos", "Christopher McQuarrie", "Ethan-Ilsa-Grace-Alanna-Luther", "Tom-Rebecca-Hayley-Vanessa-Ving");
    Pelicula Sonrie(6, "Sonrie", 1.55, "Terror", 2022, "ParamountPictures", "Estados Unidos", "Parker Finn", "Rose-Laura-Joel-Trevor-Jackson", "Sosie-Caitlin-Kyle-Jessie-Kal");
    Pelicula ElExorcistaDelPapa(7, "El exorcista del Papa", 1.43, "Terror", 2023, "Sony", "Estados Unidos", "Julius Avery", "FatherGabriel-Amy-Julia-Adella-FatherEsquibel", "Russell-Laurel-Alex-Carrie-Daniel");
    Pelicula ElEquipoRedentor(8, "El equipo redentor", 1.38, "Documental", 2022, "Netflix", "Estados Unidos", "KobeBryant-LeBronJames-CarmeloAnthony-ChrisPaul-DwightHoward");
    Pelicula HongosFantasticos(9, "Hongos fantasticos", 1.20, "Documental", 2019, "Netflix", "Estados Unidos", "Louie Schwartzberg, PaulStamets-BrieLarson-MichaelPollan-AndrewWeil-TonyHead");

    Pelicula peliculaarr[10] = {Bodas27, ElDescanso, UnaEsposaDeMentira, YDondeEstanLasRubias, RapidosYFuriosos10, MisionImposible7, Sonrie, ElExorcistaDelPapa, ElEquipoRedentor, HongosFantasticos};
    // movie moviearr[5] = {LordOfTheRings, StarWars, Inception, Interstellar, Tenet};

    // 1, 27 bodas, Pelicula, 1.51, Romance, 2008, 20thCenturyFox, Estados Unidos, Anne Fletcher, Jane-Kevin-Tess-George-Casey, Katherine-James-Malin-Edward-Judy
    // 2, El descanso, Pelicula, 2.18, Romance, 2006, UniversalPictures, Estados Unidos, Nancy Meyers, Graham-Amanda-Iris-Miles-Jasper, Jude-Cameron-Kate-Jack-Rufus
    // 3, Una esposa de mentira, Pelicula, 1.57, Comedia, 2011, ColumbiaPictures, Estados Unidos, Dennis Dugan, Daniel-Katherine-Palmer-Maggie-Devlin, Adam-Jennifer-Brooklyn-Bailee-Nicole
    // 4, Y donde estan las rubias?, Pelicula, 1.49, Comedia, 2004, ColumbiaPictures, Estados Unidos, Keenen Ivory Wayans, Marcus-Kevin-Latrell-Karen-Heather, Marlon-Shawn-Terry-Busy-Jaime
    // 5, Rapidos y furiosos 10, Pelicula, 2.21, Accion, 2023, UniversalPictures, Estados Unidos, Louis Leterrier, Dominic-Dante-Aimes-AbuelitaToretto-Letty, Vin-Jason-Alan-Rita-Michelle
    // 6, Mision Imposible 7, Pelicula, 2.43, Accion, 2023, ParamountPictures, Estados Unidos, Christopher McQuarrie, Ethan-Ilsa-Grace-Alanna-Luther, Tom-Rebecca-Hayley-Vanessa-Ving
    // 7, Sonrie, Pelicula, 1.55, Terror, 2022, ParamountPictures, Estados Unidos, Parker Finn, Rose-Laura-Joel-Trevor-Jackson, Sosie-Caitlin-Kyle-Jessie-Kal
    // 8, El exorcista del Papa, Pelicula, 1.43, Terror, 2023, Sony, Estados Unidos, Julius Avery, FatherGabriel-Amy-Julia-Adella-FatherEsquibel, Russell-Laurel-Alex-Carrie-Daniel
    // 9, El equipo redentor, Pelicula, 1.38, Documental, 2022, Netflix, Estados Unidos, KobeBryant-LeBronJames-CarmeloAnthony-ChrisPaul-DwightHoward
    // 10, Hongos fantasticos, Pelicula, 1.20, Documental, 2019, Netflix, Estados Unidos, Louie Schwartzberg, PaulStamets-BrieLarson-MichaelPollan-AndrewWeil-TonyHead

    // Creating different series objects and adding them to an array

    Serie AunAsi(0, "Aun Asi", 10, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");

    Serie seriesarr[1] = {AunAsi};

    // Creating different episode objects for Obi-Wan series and adding them to an array

    // id, titulo, tipo, duracion, genero, año, estudio, nacionalidad, director, personajes, actores
    Episodio AunAsi1(0, "Aun Asi- El destino no existe", 72, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi2(1, "Aun Asi-No soy la unica ", 66, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi3(2, "Aun Asi-Ya comezo", 75, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi4(3, "Aun Asi-Se que no es amor", 75, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi5(4, "Aun Asi-Se que nada va a cambiar", 71, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi6(5, "Aun Asi-El amor no existe", 67, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi7(6, "Aun Asi-Se que no hay vuelta atras", 63, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi8(7, "Aun Asi-Se que es una mentira", 66, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi9(8, "Aun Asi-Se que se acabo", 69, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");
    Episodio AunAsi10(9, "Aun Asi-Yo todavia", 69, "K-Drama", 2021, "Netflix", "Corea", "Kim Ga-Ram", "ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol", "SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung");

    Episodio AunAsiarr[10] = {AunAsi1, AunAsi2, AunAsi3, AunAsi4, AunAsi5, AunAsi6, AunAsi7, AunAsi8, AunAsi9, AunAsi10};

    int x;

    // id, titulo, tipo, duracion, genero, año, estudio, nacionalidad, director, personajes, actores
    // 1. El destino no existe, Episodio, 72, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 2. No soy la unica, Episodio, 66, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 3. Ya comezo, Episodio, 75, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 4. Se que no es amor,  Episodio, 75, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 5. Se que nada va a cambiar, Episodio, 71, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 6. El amor no existe, Episodio, 67, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 7. Se que no hay vuelta atras,Episodio, 63, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 8. Se que es una mentira, Episodio, 66, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 9. Se que se acabo, Episodio, 69, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung
    // 10. Aun asi yo todavia, Episodio, 69, k-drama, 2021, Netflix, Corea, Kim Ga-Ram, ParkJaeEon-YuNaBi-YangDoHyeok-OhBitNa-YoonSol, SongKang-HanSoHee-ChaeJongHyeop-YangHyeJi-LeeHoJung

    // Do while loop, which will serve as the main menu which will repeat after every action until the program is terminated

    do
    {
        std::cout << "Menu de plataforma:" << std::endl;
        std::cout << "1. Ver lista de pelicula" << std::endl;
        std::cout << "2. Ver lista de serie" << std::endl;
        std::cout << "3. See movies rated above 4 stars" << std::endl;
        std::cout << "4. See series rated above 4 stars" << std::endl;
        std::cout << "5. Ver películas de un genero especifico" << std::endl;
        std::cout << "6. Calificar una pelicula" << std::endl;
        std::cout << "7. Calificar una pelicula" << std::endl;
        std::cout << "0. Exit program" << std::endl;
        std::cin >> x;

        if (x == 1)
        {
            for (int i = 0; i <= 4; i++)
            {
                peliculaarr[i].showrating();
            }
        }
        else if (x == 2)
        {
            for (int i = 0; i <= 4; i++)
            {
                seriesarr[i].showrating();
            }
        }
        else if (x == 3)
        {
            for (int i = 0; i <= 4; i++)
            {
                if (peliculaarr[i].getRating() >= 4)
                {
                    peliculaarr[i].showrating();
                }
            }
        }
        else if (x == 4)
        {
            for (int i = 0; i <= 4; i++)
            {
                if (seriesarr[i].getRating() >= 4)
                {
                    seriesarr[i].showrating();
                }
            }
        }
        else if (x == 5)
        {
            int y;
            std::cout << "Cual es el genero que buscas?" << std::endl;
            std::cout << "1. Romance" << std::endl;
            std::cout << "2. Comedia" << std::endl;
            std::cout << "3. Accion" << std::endl;
            std::cout << "4. Terror" << std::endl;
            std::cout << "5. Documental" << std::endl;
            std::cin >> y;

            if (y == 1)
            {
                for (int i = 0; i <= 4; i++)
                {
                    if (peliculaarr[i].getGenero() == "Romance")
                    {
                        std::cout << peliculaarr[i].getTitulo() << std::endl;
                        if (seriesarr[i].getGenero() == "Romance")
                        {
                            std::cout << seriesarr[i].getTitulo() << std::endl;
                        }
                    }
                    else if (seriesarr[i].getGenero() == "Romance")
                    {
                        std::cout << seriesarr[i].getTitulo() << std::endl;
                    }
                }
            }
            else if (y == 2)
            {
                for (int i = 0; i <= 4; i++)
                {
                    if (peliculaarr[i].getGenero() == "Comedia")
                    {
                        std::cout << peliculaarr[i].getTitulo() << std::endl;
                        if (seriesarr[i].getGenero() == "Comedia")
                        {
                            std::cout << seriesarr[i].getTitulo() << std::endl;
                        }
                    }
                    else if (seriesarr[i].getGenero() == "Comedia")
                    {
                        std::cout << seriesarr[i].getTitulo() << std::endl;
                    }
                }
            }
            else if (y == 3)
            {
                for (int i = 0; i <= 4; i++)
                {
                    if (peliculaarr[i].getGenero() == "Accion")
                    {
                        std::cout << peliculaarr[i].getTitulo() << std::endl;
                        if (seriesarr[i].getGenero() == "Accion")
                        {
                            std::cout << seriesarr[i].getTitulo() << std::endl;
                        }
                    }
                    else if (seriesarr[i].getGenero() == "Accion")
                    {
                        std::cout << seriesarr[i].getTitulo() << std::endl;
                    }
                }
            }
            else if (y == 4)
            {
                for (int i = 0; i <= 4; i++)
                {
                    if (peliculaarr[i].getGenero() == "Terror")
                    {
                        std::cout << peliculaarr[i].getTitulo() << std::endl;
                        if (seriesarr[i].getGenero() == "Terror")
                        {
                            std::cout << seriesarr[i].getTitulo() << std::endl;
                        }
                    }
                    else if (seriesarr[i].getGenero() == "Terror")
                    {
                        std::cout << seriesarr[i].getTitulo() << std::endl;
                    }
                }
            }
            else if (y == 5)
            {
                for (int i = 0; i <= 4; i++)
                {
                    if (peliculaarr[i].getGenero() == "Documental")
                    {
                        std::cout << peliculaarr[i].getTitulo() << std::endl;
                        if (seriesarr[i].getGenero() == "Documental")
                        {
                            std::cout << seriesarr[i].getTitulo() << std::endl;
                        }
                    }
                    else if (seriesarr[i].getGenero() == "Documental")
                    {
                        std::cout << seriesarr[i].getTitulo() << std::endl;
                    }
                }
            }
        }
        else if (x == 6)
        {
            std::cout << "Ingrese el ID de la pelicula que desee calificar" << std::endl;
            for (int i = 0; i <= 4; i++)
            {
                std::cout << peliculaarr[i].getID() << " " << peliculaarr[i].getTitulo() << std::endl;
            }
            int z, rate;
            std::cin >> z;

            std::cout << "Ingrese la calificacion de la pelicula: ";
            std::cin >> rate;

            peliculaarr[z].setRating(rate);
        }
        else if (x == 7)
        {
            std::cout << "Ingrese el ID de la serie que desee calificar" << std::endl;
            for (int i = 0; i <= 4; i++)
            {
                std::cout << i << " " << seriesarr[i].getTitulo() << std::endl;
            }
            int z, rate;
            std::cin >> z;

            std::cout << "Ingrese la calificacion de la serie: ";
            std::cin >> rate;

            seriesarr[z].setRating(rate);
        }
    } while (x != 0);
}
