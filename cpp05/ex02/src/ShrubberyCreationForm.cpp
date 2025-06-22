#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(), target_("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  checkExecuteAuthority(executor);
  std::ofstream file((target_ + "_shrubbery").c_str());
  if (!file.is_open())
    throw std::runtime_error("Error: Failed to open file");
  file << "                                                         .\n"
       << "                                              .         ;\n"
       << "                 .              .              ;%     ;;\n"
       << "                   ,           ,                :;%  %;\n"
       << "                    :         ;                   :;%;'     .,\n"
       << "           ,.        %;     %;            ;        %;'    ,;\n"
       << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
       << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
       << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
       << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
       << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
       << "                    `:%;.  :;bd%;          %;@%;'\n"
       << "                      `@%:.  :;%.         ;@@%;'\n"
       << "                        `@%.  `;@%.      ;@@%;\n"
       << "                          `@%%. `@%%    ;@@%;\n"
       << "                            ;@%. :@%%  %@@%;\n"
       << "                              %@bd%%%bd%%:;\n"
       << "                                #@%%%%%:;;\n"
       << "                                %@@%%%::;\n"
       << "                                %@@@%(o);  . '\n"
       << "                                %@@@o%;:(.,'\n"
       << "                            `.. %@@@o%::;\n"
       << "                               `)@@@o%::;\n"
       << "                                %@@(o)::;\n"
       << "                               .%@@@@%::;\n"
       << "                               ;%@@@@%::;.\n"
       << "                              ;%@@@@%%:;;;.\n"
       << "                          ...;%@@@@@%%:;;;;,..\n";
  if (file.fail())
    throw std::runtime_error("Error: Failed to write to file");
  std::cout << target_ + "_shrubbery" << " created successfully" << std::endl;
  file.close();
}
