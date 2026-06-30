#include <stdio.h>
#include <string.h>

#define maxPriority 4
#define addtech(a,b,c) {0,a,b,c,0,0,0,0}

struct tech {
  int status;// 1 is finished, 0 is not finished
  char name[16];// Tech name
  char req1[16];// (ptech) Primary tech
  char req2[16];// (stech) Secondary tech
  short aimil;// military ai priority
  short aitech;// technology ai priority
  short aiinfra;// infrastructure ai priority
  short aicolonize;// growth/colonize ai priority
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
    addtech("Super",  "OptComp","Indust"),//Superconductor
    addtech("Chaos",  "Physic", "InfNet"),//Nonlinear Mathematics
    addtech("E=Mc2",  "Super",  "Subat"),//Applied Relativity
    addtech("Fusion", "Algor",  "Super"),//Fusion Power
    addtech("Alloys", "Subat",  "IndAuto"),//Silksteel Alloys
    addtech("Subat",  "Chemist","Poly"),//Advanced Subatomic Theory
    addtech("Chemist","Indust", "Physic"),//High Energy Chemistry
    addtech("Surface","Unified","IndRob"),//Frictionless Surfaces
    addtech("Metal",  "ProbMec","DocInit"),//Nanometallurgy
    addtech("String", "Chaos",  "Cyber"),//Superstring Theory
    addtech("MilAlg", "DocFlex","OptComp"),//Advanced Military Algorithms
    addtech("Magnets","String", "Alloys"),//Monopole Magnets
    addtech("MatComp","Metal",  "NanoMin"),//Matter Compression
    addtech("Unified","Magnets","E=Mc2"),//Unified Field Theory
    addtech("Gravity","QuanMac","MindMac"),//Graviton Theory
    addtech("Poly",   "Indust", "InfNet"),//Polymorphic Software
    addtech("AGrav",  "Gravity","DigSent"),//Applied Gravitonics
    addtech("Quantum","Surface","PlaEcon"),//Quantum Power
    addtech("SingMec","Create", "HAL9000"),//Singularity Mechanics
    addtech("ConSing","SingMec","AGrav"),//Controlled Singularity
    addtech("TempMec","Eudaim", "Matter"),//Temporal Mechanics
    addtech("ProbMec","DocSec", "Algor"),//Probability Mechanics
    addtech("Algor",  "MilAlg", "Cyber"),//Pre-Sentient Algorithms
    addtech("Solids", "MatComp","Space"),//Super Tensile Solids
    addtech("PlaNets","InfNet", "None"),//Planetary Networks
    addtech("DigSent","IndRob", "MindMac"),//Digital Sentience
    addtech("HAL9000","Space",  "DigSent"),//Self-Aware Machines
    addtech("DocInit","DocFlex","IndAuto"),//Doctrine: Initiative
    addtech("DocFlex","Mobile", "None"),//Doctrine: Flexibility
    addtech("Integ",  "EthCalc","DocLoy"),//Intellectual Integrity
    addtech("Fossil", "Chemist","Gene"),//Synthetic Fossil Fuels
    addtech("DocAir", "Fossil","DocFlex"),//Doctrine: Air Power
    addtech("DocSec", "E=Mc2",  "Alloys"),//Photon/Wave Mechanics
    addtech("MindMac","DocAir", "Neural"),//Mind/Machine Interface
    addtech("NanoMin","Magnets","SupLube"),//Nanominiaturization
    addtech("DocLoy", "Mobile", "Psych"),//Doctrine: Loyalty
    addtech("EthCalc","Psych",  "None"),//Ethical Calculus
    addtech("IndEcon","Indust", "None"),//Industrial Economics
    addtech("IndAuto","IndEcon","PlaNets"),//Industrial Automation
    addtech("CentMed","EcoEng", "CentEmp"),//Centauri Meditation
    addtech("Brain",  "Psych",  "Biogen"),//Secrets of the Human Brain
    addtech("Gene",   "Biogen", "EthCalc"),//Gene Splicing
    addtech("BioEng", "Gene",   "Neural"),//Bio-Engineering
    addtech("BioMac", "MindMac","Viral"),//Biomachinery
    addtech("Neural", "Brain",  "IndAuto"),//Neural Grafting
    addtech("Cyber",  "PlaNets","Integ"),//Cyberethics
    addtech("Eudaim", "SentEco","WillPow"),//Eudaimonia
    addtech("WillPow","HomoSup","CentPsi"),//The Will to Power
    addtech("Thresh", "Create", "TempMec"),//Threshold of Transcendence
    addtech("Matter", "NanEdit","AlphCen"),//Matter Transmission
    addtech("CentEmp","Brain",  "Ecology"),//Centauri Empathy
    addtech("EnvEcon","IndEcon","EcoEng"),//Environmental Economics
    addtech("EcoEng", "Ecology","Gene"),//Ecological Engineering
    addtech("PlaEcon","EnvEcon","Integ"),//Planetary Economics
    addtech("EcoEng2","Fusion", "EnvEcon"),//Adv. Ecological Engineering
    addtech("CentPsi","CentGen","EcoEng2"),//Centauri Psi
    addtech("AlphCen","CentPsi","SentEco"),//Secrets of Alpha Centauri
    addtech("Create", "Unified","WillPow"),//Secrets of Creation
    addtech("Space",  "Orbital","SupLube"),//Advanced Spaceflight
    addtech("HomoSup","BioMac", "DocInit"),//Homo Superior
    addtech("SupLube","Fusion", "Fossil"),//Organic Superlubricant
    addtech("QuanMac","Quantum","Metal"),//Quantum Machinery
    addtech("NanEdit","HAL9000","Solids"),//Matter Editation
    addtech("OptComp","Physic", "Poly"),//Optical Computers
    addtech("IndRob", "NanoMin","IndAuto"),//Industrial Nanorobotics
    addtech("CentGen","CentMed","Viral"),//Centauri Genetics
    addtech("SentEco","PlaEcon","DigSent"),//Sentient Econometrics
    addtech("Viral",  "BioEng", "MilAlg"),//Retroviral Engineering
    addtech("Orbital","DocAir", "Algor"),//Orbital Spaceflight
    addtech("TranT",  "Thresh", "ConSing")//Transcendent Thought
  };
  int changed, total_techs = sizeof(techlist) / sizeof(techlist[0]);
  int aimil, aitech, aiinfra, aicolonize;

  // Multi-pass resolution loop
  do {
    changed = 0;
    for (int i = 0; i < total_techs; i++) {
      if (techlist[i].status == 1) continue; // Already calculated

      int ptech = find_tech(techlist, total_techs, techlist[i].req1);
      int stech = find_tech(techlist, total_techs, techlist[i].req2);
      int focus;

      // Skip this tech for now if its prerequisites haven't finished computing yet
      if ((ptech != -1 && techlist[ptech].status == 0) || 
          (stech != -1 && techlist[stech].status == 0)) {
        continue;
      }
      if (techlist[i].aimil < techlist[ptech].aimil - 1) techlist[i].aimil = techlist[ptech].aimil - 1;
      if (techlist[i].aitech < techlist[ptech].aitech - 1) techlist[i].aitech = techlist[ptech].aitech - 1;
      if (techlist[i].aiinfra < techlist[ptech].aiinfra - 1) techlist[i].aiinfra = techlist[ptech].aiinfra - 1;
      if (techlist[i].aicolonize < techlist[ptech].aicolonize - 1) techlist[i].aicolonize = techlist[ptech].aicolonize - 1;
      if (stech != -1) {
        if (techlist[i].aimil < techlist[stech].aimil - 1) techlist[i].aimil = techlist[stech].aimil - 1;
        if (techlist[i].aitech < techlist[stech].aitech - 1) techlist[i].aitech = techlist[stech].aitech - 1;
        if (techlist[i].aiinfra < techlist[stech].aiinfra - 1) techlist[i].aiinfra = techlist[stech].aiinfra - 1;
        if (techlist[i].aicolonize < techlist[stech].aicolonize - 1) techlist[i].aicolonize = techlist[stech].aicolonize - 1;
      }

      if (techlist[ptech].aimil > techlist[ptech].aicolonize &&
          techlist[ptech].aimil > techlist[ptech].aiinfra &&
          techlist[ptech].aimil > techlist[ptech].aitech) {
        techlist[i].aimil = maxPriority;
        aimil = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req1);
        for (;techlist[focus].aimil < aimil && aimil > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aimil = aimil;
          aimil = aimil - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
        aimil = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req2);
        for (;techlist[focus].aimil < aimil && aimil > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aimil = aimil;
          aimil = aimil - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
      }
      if (techlist[ptech].aitech > techlist[ptech].aicolonize &&
          techlist[ptech].aitech > techlist[ptech].aiinfra &&
          techlist[ptech].aitech > techlist[ptech].aimil) {
        techlist[i].aitech = maxPriority;
        aitech = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req1);
        for (;techlist[focus].aitech < aitech && aitech > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aitech = aitech;
          aitech = aitech - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
        aitech = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req2);
        for (;techlist[focus].aitech < aitech && aitech > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aitech = aitech;
          aitech = aitech - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
      }
      if (techlist[ptech].aiinfra > techlist[ptech].aicolonize &&
          techlist[ptech].aiinfra > techlist[ptech].aimil &&
          techlist[ptech].aiinfra > techlist[ptech].aitech) {
        techlist[i].aiinfra = maxPriority;
        aiinfra = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req1);
        for (;techlist[focus].aiinfra < aiinfra && aiinfra > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aiinfra = aiinfra;
          aiinfra = aiinfra - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
        aiinfra = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req2);
        for (;techlist[focus].aiinfra < aiinfra && aiinfra > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aiinfra = aiinfra;
          aiinfra = aiinfra - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
      }
      if (techlist[ptech].aicolonize > techlist[ptech].aimil &&
          techlist[ptech].aicolonize > techlist[ptech].aiinfra &&
          techlist[ptech].aicolonize > techlist[ptech].aitech) {
        techlist[i].aicolonize = maxPriority;
        aicolonize = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req1);
        for (;techlist[focus].aicolonize < aicolonize && aicolonize > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aicolonize = aicolonize;
          aicolonize = aicolonize - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
        aicolonize = maxPriority - 1;
        focus = find_tech(techlist, total_techs, techlist[i].req2);
        for (;techlist[focus].aicolonize < aicolonize && aicolonize > 0 && find_tech(techlist, total_techs, techlist[focus].req1) > -1;) {
          techlist[focus].aicolonize = aicolonize;
          aicolonize = aicolonize - 1;
          focus = find_tech(techlist, total_techs, techlist[focus].req1);
        }
      }
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

  return 0;
}
