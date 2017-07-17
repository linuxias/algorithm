/**
 * @file geometru.c
 * @date 17.07.2017
 * @author linuxias
 * @brief This code is for geometric API.
 */

typedef struct Point {
	int x;
	int y;
} Point;

int ccw(Point p, Point q)
{
	return p.x * q.y - q.x * p.y;
}

int ccw_with_point(Point r, Point p, Point q)
{
	Point rp = {p.x - r.x, p.y - r.y};
	Point rq = {q.x - r.x, q.y - r.y};

	return ccw(rp, rq);
}

int is_left_turn(Point r, Point p, Point q)
{
	return ccw_with_point(r, p, q) > 0;
}

int is_right_turn(Point r, Point p, Point q)
{
	return ccw_with_point(r, p, q) < 0;
}

int is_collinear(Point r, Point p, Point q)
{
	return ccw_with_point(r, p, q) == 0;
}

int is_between(Point r, Point p, Point q)
{
	if (is_collinear(r, p, q) == 0)
		return 0;

	if (p.x != q.x)
		return (r.x <= q.x && r.x >= p.x) ||
				(r.x <= p.x && r.x >= q.x);

	return (r.y <= q.y && r.y >= p.y) ||
			(r.y <= p.y && r.y >= q.y);
}
