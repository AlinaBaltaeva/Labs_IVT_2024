#include "Graph.h"
#include <iostream>
#include <filesystem>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    sf::Font font;
    const std::string fontPaths[] = {
        "arial.ttf",                    // 1. Рядом с exe
        "fonts/arial.ttf",              // 2. В подпапке fonts
        "C:/Windows/Fonts/arial.ttf"    // 3. Системные шрифты
    };

    // Попытка загрузки шрифта
    bool fontLoaded = false;
    for (const auto& path : fontPaths) {
        if (font.loadFromFile(path)) {
            fontLoaded = true;
            break;
        }
    }

    if (!fontLoaded) {
        std::cerr << "Ошибка: не удалось загрузить arial.ttf\n";
        // Можно продолжить без шрифта или return -1;
    }

    // Создание текстового объекта (если шрифт загружен)
    sf::Text text;
    if (fontLoaded) {
        text.setFont(font);
        text.setString("Текст с Arial");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(100, 100);
    }

    RenderWindow window(VideoMode(800, 600), "Graph Visualizer");
    window.setFramerateLimit(60);

    Graph graph(false); // Ненаправленный граф

    // Инициализация графа
    for (int i = 1; i <= 6; i++) graph.InsertVertex(i);

    graph.InsertEdge(1, 2, 8);
    graph.InsertEdge(1, 6, 11);
    graph.InsertEdge(2, 3, 12);
    graph.InsertEdge(2, 5, 10);
    graph.InsertEdge(3, 4, 16);
    graph.InsertEdge(5, 4, 5);
    graph.InsertEdge(5, 6, 6);
    graph.InsertEdge(4, 6, 9);

    vector<int> bfsResult, dfsResult;
    graph.BFS(6, bfsResult);
    graph.DFS(6, dfsResult);
    auto dijkstraResult = graph.Dijkstra(6);

    cout << "Обход графа в ширину с 6: ";
    for (int v : bfsResult) cout << v << " ";
    cout << endl;

    cout << "Обход графа в глубину с 6: ";
    for (int v : dfsResult) cout << v << " ";
    cout << endl;

    cout << "Кратчайшие расстояния по алгоритму Дейкстры из вершины 6:" << endl;
    for (size_t i = 0; i < dijkstraResult.size(); i++) {
        cout << "К " << i + 1 << ": " << dijkstraResult[i] << endl;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear(Color::White);
        graph.DrawGraph(window);
        if (fontLoaded) {
            window.draw(text);  // Отрисовываем текст только если шрифт загружен
        }
        window.display();
    }

    return 0;
}