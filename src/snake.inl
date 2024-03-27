inline
int Snake::x() {
	return this->x_;
}

inline
int Snake::y() {
	return this->y_;
}

inline
int Snake::length() {
	return this->length_;
}

inline
void Snake::incLength() {
	this->length_++;
}

inline
void Snake::setX(int x) {
	this->x_ = x;
}

inline
void Snake::setY(int y) {
	this->y_ = y;
}
