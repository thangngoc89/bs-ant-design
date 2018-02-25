[%bs.raw {|require("antd/lib/grid/style")|}];

module Row = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "antd/lib/grid/row";
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
  [@bs.obj]
  external gutterBreakpointMap :
    (
      ~xs: string=?,
      ~sm: string=?,
      ~md: string=?,
      ~lg: string=?,
      ~xl: string=?,
      ~xxl: string=?,
      unit
    ) =>
    _ =
    "";
  let breakpointGutter = (~xs=?, ~sm=?, ~md=?, ~lg=?, ~xl=?, ~xxl=?, ()) =>
    /* ant design uses strings here even though it makes more sense to be number */
    gutterBreakpointMap(
      ~xs=?xs |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~sm=?sm |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~md=?md |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~lg=?lg |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~xl=?xl |> Js.Option.map([@bs] (b => string_of_int(b))),
      ~xxl=?xxl |> Js.Option.map([@bs] (b => string_of_int(b))),
      ()
    );
  [@bs.obj]
  external makePropsBase :
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
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makePropsBase(
          ~className?,
          ~_type=?Js.Option.map([@bs] (b => rowTypeToJs(b)), _type),
          ~align=?Js.Option.map([@bs] (b => rowAlignToJs(b)), align),
          ~justify=?Js.Option.map([@bs] (b => rowJustifyToJs(b)), justify),
          ~gutter?,
          ~style?,
          ~prefixCls?,
          ()
        ),
      children
    );
};

module Col = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "antd/lib/grid/col";
  [@bs.obj]
  external _colSizeMap :
    (
      ~span: int=?,
      ~order: int=?,
      ~offset: int=?,
      ~push: int=?,
      ~pull: int=?,
      unit
    ) =>
    _ =
    "";
  let complexColSize = (~span=?, ~order=?, ~offset=?, ~push=?, ~pull=?, ()) =>
    _colSizeMap(~span?, ~order?, ~offset?, ~push?, ~pull?, ());
  [@bs.obj]
  external makePropsColBase :
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
        children
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        makePropsColBase(
          ~className?,
          ~span?,
          ~order?,
          ~offset?,
          ~push?,
          ~pull?,
          ~xs?,
          ~sm?,
          ~md?,
          ~lg?,
          ~xl?,
          ~xxl?,
          ~prefixCls?,
          ~style?,
          ()
        ),
      children
    );
};