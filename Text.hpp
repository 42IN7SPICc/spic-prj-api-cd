#ifndef TEXT_H_
#define TEXT_H_

#include "UIObject.hpp"
#include "Color.hpp"
#include "BitmaskEnumerator.hpp"
#include <string>

namespace spic {

    /**
     * @brief Enumeration for different text alignments.
     */
    enum class Alignment {
        left,
        center,
        right
    };

    enum class Style {
        normal = 1 << 0,
        bold = 1 << 1,
        italic = 1 << 2,
        underline = 1 << 3,
        strikethrough = 1 << 4
    };

    /**
     * @brief Class representing a piece of text which can be rendered.
     */
    class Text : public UIObject {
        public:
            /**
             * @brief Constructor.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @param width The width of the UI object.
             * @param height The height of the UI object.
             */
            Text(const std::string& name, const std::string& tag, int layer, double width, double height);
            
            /**
             * @brief Constructor.
             * @param name The name for the game object.
             * @param tag The tag for the game object.
             * @param layer The layer for the game object.
             * @param width The width of the UI object.
             * @param height The height of the UI object.
             * @param text The content of the Text object
             * @param font The font the Text object will use to render
             * @param size The size the font will be rendered at
             * @param alignment The alignment the content will be rendered with 
             * @param color The color the content will be rendered in
             */
            Text(const std::string& name, const std::string& tag, int layer, double width, double height, const std::string& text, const std::string& font, int size, Alignment alignment, const Color& color);

            /**
             * @brief Get the content of the Text object
             * @return A reference to the content of the Text object
             */
            const std::string& Content() const { return text; }

            /**
             * @brief Set the text content of the Text object
             * @param text new content
             */
            void Content(const std::string& text);

            /**
             * @brief Get the font of the Text object
             * @return A reference to the font of the Text object
             */
            const std::string& Font() const { return font; }

            /**
             * @brief Set the font of the Text object
             * @param font the new font
             */
            void Font(const std::string& font);

            /**
             * @brief Get the size of the Text object
             * @return A reference to the size of the Text object
             */
            int Size() const { return size; }

            /**
             * @brief Set the size of the Text object
             * @param size the new size
             */
            void Size(int size);

            /**
             * @brief Get the alignment of the Text object
             * @return A reference to the alignment of the Text object
             */
            Alignment TextAlignment() const { return alignment; }

            /**
             * @brief Set the alignment of the content of the Text object
             * @param alignment the new alignment
             */
            void TextAlignment(Alignment alignment);

            /**
             * @brief Get the color of the Text object
             * @return A reference to the color of the Text object
             */
            const Color& TextColor() const { return color; }

            /**
             * @brief Set the color of the Text object
             * @param color the new color
             */
            void TextColor(const Color& color);

            void FontStyle(bitmask<Style> newStyles);

            const bitmask<Style>& FontStyle() const;

        private:
            std::string text;
            std::string font;
            int size;
            Alignment alignment;
            Color color;
            bitmask<Style> styles;
    };

}

// Enable bitmask tricks for the Style enumeration
enableEnumClassBitmask(spic::Style);

#endif // TEXT_H_
