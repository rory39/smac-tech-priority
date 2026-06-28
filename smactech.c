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
int min_priority(int limit)
{
  int num = 0, i;

  for (i = 1;i <= maxPriority;i++) {
    if (num < limit * (i - 1) / i) {
      num++;
    }
  }
  return num;
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
      int focus1 = 0, focus2 = 0;

      // Skip this tech for now if its prerequisites haven't finished computing yet
      if ((ptech != -1 && techlist[ptech].status == 0) || 
          (stech != -1 && techlist[stech].status == 0)) {
        continue;
      }

      //Find any "useful" priorities

      aimil = min_priority(techlist[ptech].aimil);
      aitech = min_priority(techlist[ptech].aitech);
      aiinfra = min_priority(techlist[ptech].aiinfra);
      aicolonize = min_priority(techlist[ptech].aicolonize);
      if (stech != -1) {
        if (min_priority(techlist[ptech].aimil) < min_priority(techlist[stech].aimil)) aimil = min_priority(techlist[stech].aimil);
        if (min_priority(techlist[ptech].aitech) < min_priority(techlist[stech].aitech)) aitech = min_priority(techlist[stech].aitech);
        if (min_priority(techlist[ptech].aiinfra) < min_priority(techlist[stech].aiinfra)) aiinfra = min_priority(techlist[stech].aiinfra);
        if (min_priority(techlist[ptech].aicolonize) < min_priority(techlist[stech].aicolonize)) aicolonize = min_priority(techlist[stech].aicolonize);
      }

      if (techlist[ptech].aimil > techlist[ptech].aicolonize &&
          techlist[ptech].aimil > techlist[ptech].aiinfra &&
          techlist[ptech].aimil > techlist[ptech].aitech) {
        focus1 = 1;
      }
      if (techlist[ptech].aitech > techlist[ptech].aicolonize &&
          techlist[ptech].aitech > techlist[ptech].aiinfra &&
          techlist[ptech].aitech > techlist[ptech].aimil) {
        focus1 = 2;
      }
      if (techlist[ptech].aiinfra > techlist[ptech].aicolonize &&
          techlist[ptech].aiinfra > techlist[ptech].aimil &&
          techlist[ptech].aiinfra > techlist[ptech].aitech) {
        focus1 = 3;
      }
      if (techlist[ptech].aicolonize > techlist[ptech].aimil &&
          techlist[ptech].aicolonize > techlist[ptech].aiinfra &&
          techlist[ptech].aicolonize > techlist[ptech].aitech) {
        focus1 = 4;
      }
      if (stech > -1) {
        if (techlist[stech].aimil > techlist[stech].aicolonize &&
            techlist[stech].aimil > techlist[stech].aiinfra &&
            techlist[stech].aimil > techlist[stech].aitech) {
          focus2 = 1;
        }
        if (techlist[stech].aitech > techlist[stech].aicolonize &&
            techlist[stech].aitech > techlist[stech].aiinfra &&
            techlist[stech].aitech > techlist[stech].aimil) {
          focus2 = 2;
        }
        if (techlist[stech].aiinfra > techlist[stech].aicolonize &&
            techlist[stech].aiinfra > techlist[stech].aimil &&
            techlist[stech].aiinfra > techlist[stech].aitech) {
          focus2 = 3;
        }
        if (techlist[stech].aicolonize > techlist[stech].aimil &&
            techlist[stech].aicolonize > techlist[stech].aiinfra &&
            techlist[stech].aicolonize > techlist[stech].aitech) {
          focus2 = 4;
        }
      }

      if (focus1 == 1) {
        switch (focus2) {
          case 2:
            if (techlist[ptech].aimil < techlist[stech].aitech) aitech = maxPriority;
            else aimil = maxPriority;
            break;
          case 3:
            if (techlist[ptech].aimil < techlist[stech].aiinfra) aiinfra = maxPriority;
            else aimil = maxPriority;
            break;
          case 4:
            if (techlist[ptech].aimil < techlist[stech].aicolonize) aicolonize = maxPriority;
            else aimil = maxPriority;
            break;
          default:
            aimil = maxPriority;
            break;
        }
      } else if (focus1 == 2) {
        switch (focus2) {
          case 1:
            if (techlist[ptech].aitech < techlist[stech].aimil) aimil = maxPriority;
            else aitech = maxPriority;
            break;
          case 3:
            if (techlist[ptech].aitech < techlist[stech].aiinfra) aiinfra = maxPriority;
            else aitech = maxPriority;
            break;
          case 4:
            if (techlist[ptech].aitech < techlist[stech].aicolonize) aicolonize = maxPriority;
            else aitech = maxPriority;
            break;
          default:
            aitech = maxPriority;
            break;
        }
      } else if (focus1 == 3) {
        switch (focus2) {
          case 1:
            if (techlist[ptech].aiinfra < techlist[stech].aimil) aimil = maxPriority;
            else aiinfra = maxPriority;
            break;
          case 2:
            if (techlist[ptech].aiinfra < techlist[stech].aitech) aitech = maxPriority;
            else aiinfra = maxPriority;
            break;
          case 4:
            if (techlist[ptech].aiinfra < techlist[stech].aicolonize) aicolonize = maxPriority;
            else aiinfra = maxPriority;
            break;
          default:
            aiinfra = maxPriority;
            break;
        }
      } else if (focus1 == 4) {
        switch (focus2) {
          case 1:
            if (techlist[ptech].aicolonize < techlist[stech].aimil) aimil = maxPriority;
            else aicolonize = maxPriority;
            break;
          case 2:
            if (techlist[ptech].aicolonize < techlist[stech].aitech) aitech = maxPriority;
            else aicolonize = maxPriority;
            break;
          case 3:
            if (techlist[ptech].aicolonize < techlist[stech].aiinfra) aiinfra = maxPriority;
            else aicolonize = maxPriority;
            break;
          default:
            aicolonize = maxPriority;
            break;
        }
      } else {
        switch (focus2) {
          case 1: aimil = maxPriority; break;
          case 2: aitech = maxPriority; break;
          case 3: aiinfra = maxPriority; break;
          case 4: aicolonize = maxPriority; break;
        }
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
