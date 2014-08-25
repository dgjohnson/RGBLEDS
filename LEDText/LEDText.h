#ifndef LEDText_h
#define LEDText_h

#define  BACKGND_ERASE   0x0000
#define  BACKGND_LEAVE   0x0001
#define  BACKGND_DIMMING 0x0002

#define  CHAR_UP         0x0000
#define  CHAR_DOWN       0x0004
#define  CHAR_LEFT       0x0008
#define  CHAR_RIGHT      0x000c

#define  SCROLL_LEFT     0x0000
#define  SCROLL_RIGHT    0x0010
#define  SCROLL_UP       0x0020
#define  SCROLL_DOWN     0x0030

#define  COLR_RGB        0x0000
#define  COLR_HSV        0x0040

#define  COLR_SINGLE     0x0000
#define  COLR_GRAD       0x0080
#define  COLR_CHAR       0x0000
#define  COLR_AREA       0x0100
#define  COLR_VERT       0x0000
#define  COLR_HORI       0x0200
// Pre combined defines to make life easier
#define  COLR_GRAD_CV    (COLR_GRAD | COLR_CHAR | COLR_VERT)
#define  COLR_GRAD_AV    (COLR_GRAD | COLR_AREA | COLR_VERT)
#define  COLR_GRAD_CH    (COLR_GRAD | COLR_CHAR | COLR_HORI)
#define  COLR_GRAD_AH    (COLR_GRAD | COLR_AREA | COLR_HORI)

#define  COLR_EMPTY      0x0400
#define  COLR_DIMMING    0x0800

#define  EFFECT_BACKGND_ERASE    "\x80"
#define  EFFECT_BACKGND_LEAVE    "\x81"
#define  EFFECT_BACKGND_DIMMING  "\x82"
#define  EFFECT_FRAME_RATE       "\x84"
#define  EFFECT_DELAY_FRAMES     "\x85"

#define  EFFECT_SCROLL_LEFT      "\x90"
#define  EFFECT_SCROLL_RIGHT     "\x91"
#define  EFFECT_SCROLL_UP        "\x92"
#define  EFFECT_SCROLL_DOWN      "\x93"

#define  EFFECT_CHAR_UP          "\xa0"
#define  EFFECT_CHAR_DOWN        "\xa1"
#define  EFFECT_CHAR_LEFT        "\xa2"
#define  EFFECT_CHAR_RIGHT       "\xa3"

#define  EFFECT_RGB              "\xc0"
#define  EFFECT_HSV              "\xc1"
#define  EFFECT_RGB_CV           "\xc2"
#define  EFFECT_HSV_CV           "\xc3"
#define  EFFECT_RGB_AV           "\xc6"
#define  EFFECT_HSV_AV           "\xc7"
#define  EFFECT_RGB_CH           "\xca"
#define  EFFECT_HSV_CH           "\xcb"
#define  EFFECT_RGB_AH           "\xce"
#define  EFFECT_HSV_AH           "\xcf"
#define  EFFECT_COLR_EMPTY       "\xd0"
#define  EFFECT_COLR_DIMMING     "\xe0"

class cLEDText
{
  public:
    void SetFont(uint8_t FontW, uint8_t FontH, uint8_t ChBase, uint8_t ChUpper, const uint8_t *FontData);
    void Init(cLEDMatrixBase *Matrix, uint16_t Width, uint16_t Height, int16_t OriginX = 0, int16_t OriginY = 0);
    void SetBackgroundMode(uint16_t Options, uint8_t Dimming = 0x00);
    void SetScrollDirection(uint16_t Options);
    void SetTextDirection(uint16_t Options);
    void SetTextColrOptions(uint16_t Options, uint8_t ColA1 = 0xff, uint8_t ColA2 = 0xff, uint8_t ColA3 = 0xff, uint8_t ColB1 = 0xff, uint8_t ColB2 = 0xff, uint8_t ColB3 = 0xff);
    void SetText(unsigned char *Txt, uint16_t TxtSize);
    int UpdateText();
  private:
    void DecodeOptions(uint16_t *tp, uint16_t *opt, uint8_t *backDim, uint8_t *col1, uint8_t *col2, uint8_t *colDim);

    cLEDMatrixBase *m_Matrix;
    uint8_t m_FontWidth, m_FontHeight, m_FontBase, m_FontUpper;
    const uint8_t *m_FontData;
    int16_t m_XMin, m_XMax, m_YMin, m_YMax;
    unsigned char *m_pText;
    uint16_t m_pSize, m_TextPos, m_Options, m_EOLtp;
    uint8_t m_XBitPos, m_YBitPos;
    uint8_t m_BackDim, m_ColDim, m_Col1[3], m_Col2[3], m_FrameRate;
    uint16_t m_LastDelayTP, m_DelayCounter;
    bool Initialised;
};

#endif
