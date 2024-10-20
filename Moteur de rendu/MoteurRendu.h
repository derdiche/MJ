#ifndef MOTEURRENDU_H
#define MOTEURRENDU_H
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <iostream>     // Pour std::cout et std::endl
#include "Math.h"
#include <chrono>
#include <vector>
#include "Algo.h"

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
            if (glewInit() != GLEW_OK) {
                glfwTerminate();
                throw std::runtime_error("Erreur : impossible d'initialiser GLEW");
            }
        
            
            // Définir la couleur de fond
            glClearColor(0.0, 0.0, 0.0, 1.0f); 
           
            // Configuration du système de coordonnées
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluOrtho2D(0, largeur, 0, hauteur); // Utilisez 0 à largeur et 0 à hauteur
            glMatrixMode(GL_MODELVIEW); // Changer le mode à MODELVIEW
        }

    void lance() {
        double lastTime = glfwGetTime();
        int nbFrames = 0;
        int i=0;

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

            ligne({1,0,0},{0,0},{799,599});
     
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
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, width, 0, height); // Ajuster la projection lors du redimensionnement
        glMatrixMode(GL_MODELVIEW); // Repasser au mode MODELVIEW
    }

    inline void pix(Vect3 rgb, Vect2 pos) {
        glBegin(GL_POINTS);
        glColor3f(rgb.x, rgb.y, rgb.z);
        glVertex2i(pos.x, pos.y);
        glEnd();
        glFlush();
    }
   
    void ligne( const Vect3 rgb, const Vect2 debut,const Vect2 fin) {
        std::vector<Vect2> pixels =dda(debut, fin);
        for (const auto& pixel : pixels) {
            pix(rgb,pixel);
        }
    }

   
};

#endif 