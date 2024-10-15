#ifndef MOTEURRENDU_H
#define MOTEURRENDU_H

#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

class MoteurRendu {
    GLFWwindow* fenetre;
    
public:
    MoteurRendu(int largeur = 800, int hauteur = 600) {
        if (!glfwInit()) {
            throw std::runtime_error("Échec de l'initialisation de GLFW");
        }
        
        fenetre = glfwCreateWindow(largeur, hauteur, "MJ", nullptr, nullptr);
        if (!fenetre) {            
            glfwTerminate(); // Terminer GLFW en cas d'erreur
            throw std::runtime_error("Échec de la création de la fenêtre GLFW");
        }
        
        glfwMakeContextCurrent(fenetre);
        glfwSetFramebufferSizeCallback(fenetre, adapteRedimension);
        glfwSwapInterval(1); // Activer la synchronisation verticale (V-Sync)
    }

   void lance() {
    double lastTime = glfwGetTime();
    int nbFrames = 0;

    glClearColor(0.0f, 1.0f, 0.0f, 1.0f); 

    while (!glfwWindowShouldClose(fenetre)) {
        // Effacer le tampon de couleur
        glClear(GL_COLOR_BUFFER_BIT);

        // Calculer les FPS
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        nbFrames++;
        
        if (deltaTime >= 1.0) { // Si une seconde s'est écoulée
            std::cout << "FPS: " << nbFrames << std::endl; // Afficher le nombre de FPS
            nbFrames = 0; // Réinitialiser le compteur
            lastTime = currentTime; // Mettre à jour le temps pour la prochaine période
        }

        // Échanger les tampons
        glfwSwapBuffers(fenetre);

        // Poll des événements
        glfwPollEvents();
    }
    
    glfwDestroyWindow(fenetre);
    glfwTerminate();
}

    static void adapteRedimension(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
};

#endif 
