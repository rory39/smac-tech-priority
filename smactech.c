#include <stdio.h>
#include <string.h>

#define addtech(a,b,c) {0,a,b,c,0,0,0,0}
struct tech {
  short status;
  char name[16];
  char req1[16];
  char req2[16];
  short aimil;
  short aitech;
  short aiinfra;
  short aicolonize;
};

// Helper function to find a tech index safely, returns -1 if not found
int find_tech(struct tech list[], int count, const char* name) {
  if (strcmp(name, "None") == 0) return -1;
  for (int i = 0; i < count; i++) {
    if (strcmp(list[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}
int main() {
  struct tech techlist[] = {
    {1,"Biogen","None","None", 0,3,2,2},
    {1,"Indust","None","None", 2,1,3,0},
    {1,"InfNet","None","None", 0,3,2,1},
    {1,"Physic","None","None", 4,2,1,0},
    {1,"Psych","None","None",  0,1,3,2},
    {1,"Mobile","None","None", 2,0,0,3},
    {1,"Ecology","None","None",0,1,2,3},
    addtech("Super",  "OptComp","Indust"),
    addtech("Chaos",  "Physic","InfNet"),
    addtech("E=Mc2",  "Super","Subat"),
    addtech("Fusion", "Algor","Super"),
    addtech("Alloys", "Subat","IndAuto"),
    addtech("Subat",  "Chemist","Poly"),
    addtech("Chemist","Indust","Ecology"),
    addtech("Surface","Unified","IndRob"),
    addtech("Metal",  "ProbMec","DocInit"),
    addtech("String", "Chaos","Cyber"),
    addtech("MilAlg", "DocFlex","OptComp"),
    addtech("Magnets","String","Alloys"),
    addtech("MatComp","Metal","NanoMin"),
    addtech("Unified","Magnets","E=Mc2"),
    addtech("Gravity","QuanMac","MindMac"),
    addtech("Poly",   "Indust","InfNet"),
    addtech("AGrav",  "Gravity","DigSent"),
    addtech("Quantum","Surface","PlaEcon"),
    addtech("SingMec","Create","HAL9000"),
    addtech("ConSing","SingMec","AGrav"),
    addtech("TempMec","Eudaim","Matter"),
    addtech("ProbMec","DocSec","Algor"),
    addtech("Algor",  "MilAlg","Cyber"),
    addtech("Solids", "MatComp","Space"),
    addtech("PlaNets","InfNet","None"),
    addtech("DigSent","IndRob","MindMac"),
    addtech("HAL9000","Space","DigSent"),
    addtech("DocInit","DocFlex","IndAuto"),
    addtech("DocFlex","Mobile","None"),
    addtech("Integ",  "EthCalc","DocLoy"),
    addtech("Fossil", "Chemist","Gene"),
    addtech("DocAir", "Fossil","DocFlex"),
    addtech("DocSec", "E=Mc2","Alloys"),
    addtech("MindMac","DocAir","Neural"),
    addtech("NanoMin","Magnets","SupLube"),
    addtech("DocLoy", "Mobile","Psych"),
    addtech("EthCalc","Psych","None"),
    addtech("IndEcon","Indust","None"),
    addtech("IndAuto","IndEcon","PlaNets"),
    addtech("CentMed","EcoEng","CentEmp"),
    addtech("Brain",  "Psych","Biogen"),
    addtech("Gene",   "Biogen","EthCalc"),
    addtech("BioEng", "Gene","Neural"),
    addtech("BioMac", "MindMac","Viral"),
    addtech("Neural", "Brain","IndAuto"),
    addtech("Cyber",  "PlaNets","Integ"),
    addtech("Eudaim", "SentEco","WillPow"),
    addtech("WillPow","HomoSup","CentPsi"),
    addtech("Thresh", "Create","TempMec"),
    addtech("Matter", "NanEdit","AlphCen"),
    addtech("CentEmp","Brain","Ecology"),
    addtech("EnvEcon","IndEcon","EcoEng"),
    addtech("EcoEng", "Ecology","Gene"),
    addtech("PlaEcon","EnvEcon","Integ"),
    addtech("EcoEng2","Fusion","EnvEcon"),
    addtech("CentPsi","CentGen","EcoEng2"),
    addtech("AlphCen","CentPsi","SentEco"),
    addtech("Create", "Unified","WillPow"),
    addtech("Space",  "Orbital","SupLube"),
    addtech("HomoSup","BioMac","DocInit"),
    addtech("SupLube","Fusion","Fossil"),
    addtech("QuanMac","Quantum","Metal"),
    addtech("NanEdit","HAL9000","Solids"),
    addtech("OptComp","Physic","Poly"),
    addtech("IndRob", "NanoMin","IndAuto"),
    addtech("CentGen","CentMed","Viral"),
    addtech("SentEco","PlaEcon","DigSent"),
    addtech("Viral",  "BioEng","MilAlg"),
    addtech("Orbital","DocAir","Algor"),
    addtech("TranT",  "Thresh","ConSing")
  };

  int changed, aimil, aitech, aiinfra, aicolonize, total_techs = sizeof(techlist) / sizeof(techlist[0]);

  // Multi-pass resolution loop
  do {
    changed = 0;
    for (int i = 0; i < total_techs; i++) {
      if (techlist[i].status == 1) continue; // Already calculated

      int ptech = find_tech(techlist, total_techs, techlist[i].req1);
      int stech = find_tech(techlist, total_techs, techlist[i].req2);

      // Skip this tech for now if its prerequisites haven't finished computing yet
      if ((ptech != -1 && techlist[ptech].status == 0) || 
          (stech != -1 && techlist[stech].status == 0)) {
        continue;
      }

      aimil = aitech = aiinfra = aicolonize = 0;
      if (ptech > -1) {
        if (aimil < techlist[ptech].aimil) aimil++;
        if (aitech < techlist[ptech].aitech) aitech++;
        if (aiinfra < techlist[ptech].aiinfra) aiinfra++;
        if (aicolonize < techlist[ptech].aicolonize) aicolonize++;
      }

      if (stech > -1) {
        if (aimil < techlist[stech].aimil - 1) aimil++;
        if (aitech < techlist[stech].aitech - 1) aitech++;
        if (aiinfra < techlist[stech].aiinfra - 1) aiinfra++;
        if (aicolonize < techlist[stech].aicolonize - 1) aicolonize++;
      }

      if (ptech > -1) {
        if (techlist[ptech].aimil >
                 (techlist[ptech].aicolonize +
                  techlist[ptech].aiinfra +
                  techlist[ptech].aitech) / 3)
          aimil++;
        if (techlist[ptech].aitech >
                 (techlist[ptech].aicolonize +
                  techlist[ptech].aimil +
                  techlist[ptech].aiinfra) / 3)
          aitech++;
        if (techlist[ptech].aiinfra >
                 (techlist[ptech].aicolonize +
                  techlist[ptech].aimil +
                  techlist[ptech].aitech) / 3)
          aiinfra++;
        if (techlist[ptech].aicolonize >
            (techlist[ptech].aimil +
             techlist[ptech].aitech +
             techlist[ptech].aiinfra) / 3)
          aicolonize++;
      }
      if (stech > -1) {
        if (techlist[stech].aimil >
            (techlist[stech].aicolonize +
             techlist[stech].aiinfra +
             techlist[stech].aitech) / 3 + 1)
          aimil++;
        if (techlist[stech].aitech >
            (techlist[stech].aicolonize +
             techlist[stech].aimil +
             techlist[stech].aiinfra) / 3 + 1)
          aitech++;
        if (techlist[stech].aiinfra >
            (techlist[stech].aicolonize +
             techlist[stech].aimil +
             techlist[stech].aitech) / 3 + 1)
          aiinfra++;
        if (techlist[stech].aicolonize >
            (techlist[stech].aimil +
             techlist[stech].aitech +
             techlist[stech].aiinfra) / 3 + 1)
          aicolonize++;
      }

      if (ptech > -1) {
        if (techlist[ptech].aimil >
                 (techlist[ptech].aicolonize +
                  techlist[ptech].aiinfra +
                  techlist[ptech].aitech) / 3)
          aimil++;
        if (techlist[ptech].aitech >
                 (techlist[ptech].aicolonize +
                  techlist[ptech].aimil +
                  techlist[ptech].aiinfra) / 3)
          aitech++;
        if (techlist[ptech].aiinfra >
                 (techlist[ptech].aicolonize +
                  techlist[ptech].aimil +
                  techlist[ptech].aitech) / 3)
          aiinfra++;
        if (techlist[ptech].aicolonize >
            (techlist[ptech].aimil +
             techlist[ptech].aitech +
             techlist[ptech].aiinfra) / 3)
          aicolonize++;
      }
      if (stech > -1) {
        if (techlist[stech].aimil >
            (techlist[stech].aicolonize +
             techlist[stech].aiinfra +
             techlist[stech].aitech) / 3 - 1)
          aimil++;
        if (techlist[stech].aitech >
            (techlist[stech].aicolonize +
             techlist[stech].aimil +
             techlist[stech].aiinfra) / 3 - 1)
          aitech++;
        if (techlist[stech].aiinfra >
            (techlist[stech].aicolonize +
             techlist[stech].aimil +
             techlist[stech].aitech) / 3 - 1)
          aiinfra++;
        if (techlist[stech].aicolonize >
            (techlist[stech].aimil +
             techlist[stech].aitech +
             techlist[stech].aiinfra) / 3 - 1)
          aicolonize++;
      }

      // Save results and mark progress
      techlist[i].aimil = aimil;
      techlist[i].aitech = aitech;
      techlist[i].aiinfra = aiinfra;
      techlist[i].aicolonize = aicolonize;
      techlist[i].status = 1;
      changed = 1;
    }
  } while (changed);

  for (int i = 0; i < total_techs; i++) {
    printf("%s,%d,%d,%d,%d,%s,%s\n",
           techlist[i].name,
           techlist[i].aimil,
           techlist[i].aitech,
           techlist[i].aiinfra,
           techlist[i].aicolonize,
           techlist[i].req1,
           techlist[i].req2);
  }

  return 0;
}
