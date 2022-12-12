//this file is for "windows", other large texts and text related functions
#include <string>
#include<iostream>
#include"Header.h"
using namespace std;

const string Names[]
{
"Juhani",
"Olavi",
"Antero",
"Tapani",
"Johannes",
"Tapio",
"Mikael",
"Kalevi",
"Matti",
"Pekka",
"Petteri",
"Ilmari",
"Sakari",
"Matias",
"Antti",
"Juha",
"Kristian",
"Heikki",
"Timo",
"Mikko",
"Kari",
"Markus",
"Jari",
"Aleksi",
"Jukka",
"Markku",
"Jaakko",
"Kalervo",
"Oskari",
"Petri",
"Mika",
"Henrik",
"Lauri",
"Veikko",
"Hannu",
"Ville",
"Erkki",
"Seppo",
"Valtteri",
"Janne",
"Ari",
"Marko",
"Ensio",
"Tuomas",
"Sami",
"Pentti",
"Juho",
"Elias",
"Eero",
"Erik",
"Martti",
"Maria",
"Helena",
"Anneli",
"Johanna",
"Kaarina",
"Marjatta",
"Hannele",
"Kristiina",
"Emilia",
"Liisa",
"Elina",
"Sofia",
"Tuulikki",
"Maarit",
"Susanna",
"Annikki",
"Leena",
"Katariina",
"Anna",
"Marja",
"Sinikka",
"Inkeri",
"Riitta",
"Aino",
"Anne",
"Tuula",
"Kyllikki",
"Paivi",
"Orvokki",
"Ritva",
"Maija",
"Tellervo",
"Karoliina",
"Pauliina",
"Pirjo",
"Minna",
"Sari",
"Irmeli",
"Eveliina",
"Tiina",
"Eeva",
"Laura",
"Marika",
"Elisabet",
"Tarja",
"Satu",
"Pirkko",
"Mari",
"Hanna" 
};
const string Surnames[]
{
	"Korhonen",
"Virtanen",
"Makinen",
"Nieminen",
"Makela",
"Hamalainen",
"Laine",
"Heikkinen",
"Koskinen",
"Jarvinen",
"Lehtonen",
"Lehtinen",
"Saarinen",
"Salminen",
"Heinonen",
"Heikkila",
"Niemi",
"Kinnunen",
"Salonen",
"Turunen",
"Salo",
"Laitinen",
"Tuominen",
"Rantanen",
"Karjalainen",
"Jokinen",
"Mattila",
"Savolainen",
"Lahtinen",
"Ahonen",
"Ojala",
"Leppanen",
"Kallio",
"Vaisanen",
"Leinonen",
"Hiltunen",
"Miettinen",
"Pitkanen",
"Aaltonen",
"Manninen",
"Koivisto",
"Hakala",
"Anttila",
"Laaksonen",
"Hirvonen",
"Rasanen",
"Lehto",
"Laakso",
"Toivonen",
"Rantala",
"Mustonen",
"Aalto",
"Niemela",
"Nurmi",
"Moilanen",
"Peltonen",
"Seppala",
"Pulkkinen",
"Hanninen",
"Saari",
"Lappalainen",
"Kettunen",
"Partanen",
"Kemppainen",
"Kauppinen",
"Koskela",
"Seppanen",
"Ahola",
"Salmi",
"Lahti",
"Huttunen",
"Ikonen",
"Aho",
"Suominen",
"Karkkainen",
"Pesonen",
"Halonen",
"Nyman",
"Mikkonen",
"Koponen",
"Johansson",
"Peltola",
"Oksanen",
"Lindholm",
"Niskanen",
"Vainio",
"Heiskanen",
"Mikkola",
"Honkanen",
"Koski",
"Immonen",
"Nurminen",
"Vuorinen",
"Harju",
"Maatta",
"Kokkonen",
"Rissanen",
"Karppinen",
"Maki",
"Rajala",
"Laukkanen",
};
const string EnterWindow = {
"X----------------------ROOM BOOKING---------------------X\n"
"|This program helps you to book room in our hotel.      |\n"
"|Please, choose  the command from the list below:       |\n"
"|                                                       |\n"
"| 1.Check reservation status                            |\n"
"| 2.Make a new order                                    |\n"
"| 3.Admin info                                          |\n"
"| 4.Exit                                                |\n"
"X-------------------------------------------------------X\n"
};
const string Answer = {
"\nI want execute command number : "
};
const string ReservationWindow = {
"X---------------------BOOKING STATUS--------------------X\n"
"|Please, enter your name or order number.               |\n"
"|                                                       |\n"
"X-------------------------------------------------------X\n"
"\n"
"My order number(or name) is : "
};
const string DrawPersData = {
"X---------------------Orders----------------------------X\n"
"|Please, enter your name or order number.               |\n"
"|                                                       |\n"
"X-------------------------------------------------------X\n"
};
const string NewOrder = {
"X---------------------Orders----------------------------X\n"
"|Please, enter the date of arrival.                     |\n"
"|                                                       |\n"
"X-------------------------------------------------------X\n"
}; const string NewOrder2 = {
"X---------------------Orders----------------------------X\n"
"|Please, enter the date of departure.                   |\n"
"|                                                       |\n"
"X-------------------------------------------------------X\n"
};



