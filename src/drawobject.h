#ifndef DRAWOBJECT_H
#define DRAWOBJECT_H

class DrawObject
{

public:
    DrawObject()
    {
        m_data_size = 0;
        m_data_offset = 0;
        m_first_to_draw = 0;
        m_number_to_draw = 0;
    }
    virtual ~DrawObject()
    {
    }

    virtual unsigned int GetDrawType() const = 0;
	virtual const void* GetData() const = 0;

    void SetFirstToDraw(unsigned int first) { m_first_to_draw = first; }
    unsigned int GetFirstToDraw() const     { return m_first_to_draw; }
    unsigned int GetNumberToDraw() const    { return m_number_to_draw; }
    unsigned int GetDataSize() const        { return m_data_size; }
    void SetDataOffset(unsigned int offset) { m_data_offset = offset; }
    unsigned int GetDataOffset() const      { return m_data_offset; }

protected:

    unsigned int m_data_size;
    unsigned int m_data_offset;
    unsigned int m_first_to_draw;
    unsigned int m_number_to_draw;

};

#endif // DRAWOBJECT_H
