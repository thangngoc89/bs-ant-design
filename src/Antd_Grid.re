[%bs.raw {|require("antd/lib/grid/style")|}];

module Row = {
  [@bs.module "antd/lib/grid/row"]
  external reactClass: ReasonReact.reactClass = "default";
  [@bs.deriving jsConverter]
  type rowType = [ | `flex];
  [@bs.deriving jsConverter]
  type rowAlign = [ | `top | `middle | `bottom];
  [@bs.deriving jsConverter]
  type rowJustify = [
    | `start
    | [@bs.as "end"] `end_
    | `center
    | `spaceAround
    | `spaceBetween
  ];
  type gutterBreakpoints;
  [@bs.obj]
  external makeStringGutterConfig:
    (
      ~xs: string=?,
      ~sm: string=?,
      ~md: string=?,
      ~lg: string=?,
      ~xl: string=?,
      ~xxl: string=?,
      unit
    ) =>
    gutterBreakpoints =
    "";
  let makeGutterBreakpoints = (~xs=?, ~sm=?, ~md=?, ~lg=?, ~xl=?, ~xxl=?, ()) =>
    /* ant design uses strings here even though it makes more sense to be number */
    makeStringGutterConfig(
      ~xs=?xs |> Js.Option.map((. b) => string_of_int(b)),
      ~sm=?sm |> Js.Option.map((. b) => string_of_int(b)),
      ~md=?md |> Js.Option.map((. b) => string_of_int(b)),
      ~lg=?lg |> Js.Option.map((. b) => string_of_int(b)),
      ~xl=?xl |> Js.Option.map((. b) => string_of_int(b)),
      ~xxl=?xxl |> Js.Option.map((. b) => string_of_int(b)),
      (),
    );
  type gutter(_) =
    | SingleGutterInPx(int): gutter(int)
    | ResponsiveBreakpoints(gutterBreakpoints): gutter(gutterBreakpoints);
  let gutterToProp = (type a, gutter: gutter(a)): a =>
    switch (gutter) {
    | SingleGutterInPx(int) => int
    | ResponsiveBreakpoints(complexGutter) => complexGutter
    };
  [@bs.obj]
  external makeProps:
    (
      ~className: string=?,
      ~_type: string=?,
      ~align: string=?,
      ~justify: string=?,
      ~gutter: 'a=?,
      ~style: ReactDOMRe.Style.t=?,
      ~prefixCls: string=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className=?,
        ~gutter=?,
        ~_type=?,
        ~align=?,
        ~justify=?,
        ~style=?,
        ~prefixCls=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~_type=?Js.Option.map((. b) => rowTypeToJs(b), _type),
          ~align=?Js.Option.map((. b) => rowAlignToJs(b), align),
          ~justify=?Js.Option.map((. b) => rowJustifyToJs(b), justify),
          ~gutter=?Js.Option.map((. b) => gutterToProp(b), gutter),
          ~style?,
          ~prefixCls?,
          (),
        ),
      children,
    );
};

module Col = {
  [@bs.module "antd/lib/grid/col"]
  external reactClass: ReasonReact.reactClass = "default";
  type fullColSize;
  [@bs.obj]
  external makeColSize:
    (
      ~span: int=?,
      ~order: int=?,
      ~offset: int=?,
      ~push: int=?,
      ~pull: int=?,
      unit
    ) =>
    fullColSize =
    "";
  type colSize(_) =
    | SingleColSize(int): colSize(int)
    | FullColSize(fullColSize): colSize(fullColSize);
  let colSizeToProp = (type a, colSize: colSize(a)): a =>
    switch (colSize) {
    | SingleColSize(int) => int
    | FullColSize(fullColSize) => fullColSize
    };
  [@bs.obj]
  external makeProps:
    (
      ~className: string=?,
      ~span: int=?,
      ~order: int=?,
      ~offset: int=?,
      ~push: int=?,
      ~pull: int=?,
      ~xs: 'a=?,
      ~sm: 'b=?,
      ~md: 'c=?,
      ~lg: 'd=?,
      ~xl: 'e=?,
      ~xxl: 'f=?,
      ~prefixCls: string=?,
      ~style: ReactDOMRe.Style.t=?,
      unit
    ) =>
    _ =
    "";
  let make =
      (
        ~className=?,
        ~span=?,
        ~order=?,
        ~offset=?,
        ~push=?,
        ~pull=?,
        ~xs=?,
        ~sm=?,
        ~md=?,
        ~lg=?,
        ~xl=?,
        ~xxl=?,
        ~prefixCls=?,
        ~style=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makeProps(
          ~className?,
          ~span?,
          ~order?,
          ~offset?,
          ~push?,
          ~pull?,
          ~xs=?Js.Option.map((. b) => colSizeToProp(b), xs),
          ~sm=?Js.Option.map((. b) => colSizeToProp(b), sm),
          ~md=?Js.Option.map((. b) => colSizeToProp(b), md),
          ~lg=?Js.Option.map((. b) => colSizeToProp(b), lg),
          ~xl=?Js.Option.map((. b) => colSizeToProp(b), xl),
          ~xxl=?Js.Option.map((. b) => colSizeToProp(b), xxl),
          ~prefixCls?,
          ~style?,
          (),
        ),
      children,
    );
};

let makeGutterBreakpoints = Row.makeGutterBreakpoints;

let makeColSize = Col.makeColSize;