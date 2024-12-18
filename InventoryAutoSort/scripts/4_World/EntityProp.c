class EntityProperty
{
    EntityAI    entity;
    int         area;
    int         width, height;
    bool        flip;

    void EntityProperty( EntityAI _entity, int _width, int _height, bool _flip )
    {
        entity  = _entity;
        width   = _width;
        height  = _height;
        area    = _width * _height;
        flip    = _flip;
    }
}
