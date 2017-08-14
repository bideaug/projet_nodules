#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class GnuPlotScriptFactory
{
public:
    //Paramètres booleens pour les options des plots
    bool plotting_DCVD = false;
    bool plotting_DCT = true;
    bool plotting_DSOL = false;
    bool plotting_density = false;
    bool display_legend = false;

public:
    //Methode qui gére l'attribution des paramètres
    void setplotparameters();
    //Automatisation du questionnement sur les paramètres
    bool parameterfiller(std::string question);
    //Génère un scipt gnuplot en fonction des données contenu dans le répertoire contenu dans folder_path
    //note le scipt est placé dans le répertoire output_file_path
    void generate_script_from_files(std::string folder_path, std::string output_file_path);

private:
    //liste les fichiers qui vont faire partie du plot tout les .dat dans le répertoire du file_path
    std::string get_plot_from_file(std::string file_path);

    //Si plotting_DCT est vrai génére le code gnuplot correspondant
    std::string dct_plot(std::string file_path);

    //Si plotting_DCVD est vrai génére le code gnuplot correspondant
    std::string dcvd_plot(std::string file_path);

    //Si plotting_SOL est vrai génére le code gnuplot correspondant
    std::string dsol_plot(std::string file_path);

    //Si plotting_density est vrai génére le code gnuplot correspondant
    std::string density_ct_plot(std::string file_path);

    //Si plotting_density est vrai génére le code gnuplot correspondant
    std::string density_sol_plot(std::string file_path);

    //récupère l'entete du fichier gnuplot
    std::string get_plot_head();

    //génére le corps de l'entré pour le fichier gnuplot
    std::string generic_plot(std::string file_path);

    //récupère le nom du plot en fonction du type de plot (taille ou densité)
    std::string get_plot_title(std::string file_path);

    //Met la légende dans le plot ou l'enlève en fonction de la valeur de display_legend
    std::string get_legend(std::string file_path, std::string ending);

    //Génère l'entete du fichier gnuplot.cmd
    std::string get_head();

    //Génère la fin du fichier gnuplot.cmd
    std::string get_tail();

private:
    //compte les nombres de fois qu'on a plot
    int plot_amount;

public:
    //Constructeur vide
    GnuPlotScriptFactory();
};
