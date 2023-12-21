/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
20/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

int main(int argc, char* argv[]){
  sql::Driver *dr;
  sql::Connection *cnx;
  sql::Statement *st;
  dr = get_driver_instance();
  cnx = dr->connect("localhost", "root", "adminx");
  cnx->setSchema("FORMAPRO");
  st = cnx->createStatement();
  std::string num = "8000";
  std::string intitule = "CUISINE";
  std::string requete = "INSERT INTO cours (numco, intitule) VALUES ('" + num + "', '" + intitule + "')";
  st->execute(requete);
  std::cout << "Cours ajouté avec succès!" << std::endl;
  return 0;
}