# Assignment7
classDiagram
    class Controller {
        - Snake* _snake
        - food* _food
        - View& _view
        - bool _gameOver
        + Controller(View&)
        + ~Controller()
        + run()
        - checkCollision()
        - createNewfood()
        - handleInput(int)
    }

    class View {
        - int _termWidth
        - int _termHeight
        - vector~vector~string~~ latest_map, last_map
        - vector~vector~Color~~ latest_fg_color, last_fg_color
        - vector~vector~Color~~ latest_bg_color, last_bg_color
        + View()
        + render()
        + updateGameObject(GameObject*)
        + resetLatest()
    }

    class GameObject {
        # Position _pos
        # Icon _icon
        + GameObject()
        + Position getPosition() const
        + Icon getIcon() const
        + virtual void update()
    }

    class Snake {
        - vector~Position~ Body
        + Direction Dir
        + Snake(Position)
        + grow()
        + update() override
        + bool check()
        + Position getHeadPosition()
        + const vector~Position~& getbody() const
    }

    class food {
        + food(Position)
        + respawn(Position)
    }

    class GameObjectFactory {
        <<static>>
        + static Snake* createSnake()
        + static food* createfood()
    }

    class IconFactory {
        <<static>>
        + static Icon createSnakeHeadIcon()
        + static Icon createfood()
        + static Icon createSnakeBodyIcon()
    }
    
    class Icon
    class Cell
    class Position
    
    Controller --* Snake
    Controller --* food
    Controller --o View
    Controller ..> GameObjectFactory
    Controller ..> IconFactory
    
    View ..> GameObject
    View ..> Position
    View ..> Cell
    View ..> Icon
    
    Snake --|> GameObject
    food --|> GameObject
    
    GameObject --* Position
    GameObject --* Icon
    
    Snake ..> IconFactory
    food ..> IconFactory

    Icon "1" --* "n" Cell : contains
