/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2012 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/
//mapnik
#include <mapnik/text/placement_finder_ng.hpp>

//boost
#include <boost/make_shared.hpp>

namespace mapnik
{

placement_finder_ng::placement_finder_ng( Feature const& feature, DetectorType &detector, box2d<double> const& extent)
    : feature_(feature), detector_(detector), extent_(extent)
{
}

glyph_positions_ptr placement_finder_ng::find_point_placement(text_layout_ptr layout, double pos_x, double pos_y, double angle)
{
    glyph_positions_ptr glyphs = boost::make_shared<glyph_positions>(layout);
    glyphs->point_placement(pos_x, pos_y);
    //TODO: angle
    //TODO: Check for placement
    return glyphs;
}

glyph_positions::glyph_positions(text_layout_ptr layout)
    : x_(0), y_(0), point_(true), layout_(layout)
{

}

void glyph_positions::point_placement(double x, double y)
{
    x_ = x;
    y_ = y;
    point_ = true;
}


}// ns mapnik