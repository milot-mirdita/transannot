#ifndef LOCALPARAMETERS_H
#define LOCALPARAMETERS_H

#include <Parameters.h>

class LocalParameters : public  Parameters {
public:
    static void initInstance() {
        new LocalParameters;
    }

    static LocalParameters& getLocalInstance() {
        if (instance == nullptr) {
            initInstance();
        }
        return static_cast<LocalParameters&>(LocalParameters::getInstance());
    }

    std::vector<MMseqsParameter*> assembly;
    std::vector<MMseqsParameter*> annotateworkflow;
    std::vector<MMseqsParameter*> downloaddb;
    std::vector<MMseqsParameter*> contaminationworkflow;
    std::vector<MMseqsParameter*> createdb;


    std::vector<MMseqsParameter*> combineList(const std::vector<MMseqsParameter*> &par1,
                                            const std::vector<MMseqsParameter*> &par2);

private:
    LocalParameters() :
        Parameters(),


    {
        downloaddb.push_back(&PARAM_HELP);
        downloaddb.push_back(&PARAM_HELP_LONG);
    }
    LocalParameters(LocalParameters const&);
    ~LocalParameters() {};
    void operator=(LocalParameters const&);
};

#endif