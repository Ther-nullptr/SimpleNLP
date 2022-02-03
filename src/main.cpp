#include <iostream>
#include <iomanip>
#include "../include/simple_nlp.h"
#include "../tclap/include/tclap/CmdLine.h"

int main(int argc, char **argv)
{
    bool v_ed;
    bool v_cer;
    bool v_info;
    std::string v_hyp;
    std::string v_ref;
    try
    {
        TCLAP::CmdLine cmd("Simple NLP executable file. Able to calculate edit distance and CER.");

        TCLAP::SwitchArg ed("d", "edit_distance", "calculate the edit distance of two strings.");
        cmd.add(ed);
        TCLAP::SwitchArg cer("c", "CER", "calculate the CER of two strings.");
        cmd.add(cer);
        TCLAP::SwitchArg detail("x", "detailed", "show the detailed info of the calculate result.");
        cmd.add(detail);

        TCLAP::ValueArg<std::string> hyp("y", "hyp", "hypnosis string", true, "", "std::string");
        cmd.add(hyp);
        TCLAP::ValueArg<std::string> ref("r", "ref", "reference string", true, "", "std::string");
        cmd.add(ref);

        cmd.parse(argc, argv);

        v_ed = ed.getValue();
        v_cer = cer.getValue();
        v_info = detail.getValue();
        v_hyp = hyp.getValue();
        v_ref = ref.getValue();
    }

    catch (TCLAP::ArgException &e) // catch exceptions
    {
        std::cerr << "Parsing error: " << e.error() << " for arg " << e.argId() << std::endl;
        return 1;
    }

    if (v_ed)
    {
        std::cout << "edit distance: " << edit_distance(v_hyp, v_ref) << std::endl;
    }

    if (v_cer)
    {
        std::cout << "CER: " << CER(v_hyp, v_ref) << std::endl;
    }

    if (v_info)
    {
        NLP_Info cal_info = get_details(v_hyp, v_ref);
        std::cout << std::setiosflags(std::ios::left);
        std::cout << "hyp: " << std::setw(30) << cal_info.hyp << std::endl
                  << "ref: " << std::setw(30) << cal_info.ref << std::endl
                  << "edit distance: " << std::setw(30) << cal_info.edit_distance << std::endl
                  << "CER: " << std::setw(30) << cal_info.CER << std::endl
                  << "substitution characters: " << std::setw(30) << cal_info.S << std::endl
                  << "deletion characters: " << std::setw(30) << cal_info.D << std::endl
                  << "insertion characters: " << std::setw(30) << cal_info.I << std::endl
                  << "correct characters: " << std::setw(30) << cal_info.C << std::endl
                  << "wrong characters: " << std::setw(30) << cal_info.W << std::endl;
    }

    return 0;
}