[@bs.module "antd/lib/popover"]
external reactClass: ReasonReact.reactClass = "default";

[%bs.raw {|require("antd/lib/popover/style")|}];

type placement = [
  | `top
  | `left
  | `right
  | `bottom
  | `topLeft
  | `topRight
  | `bottomLeft
  | `bottomRight
  | `leftTop
  | `leftBottom
  | `rightTop
  | `rightBottom
];

[@bs.deriving jsConverter]
type trigger = [ | `hover | `focus | `click | `contextMenu];

[@bs.obj]
external makeProps:
  (
    ~prefixCls: string=?,
    ~overlayClassName: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~overlayStyle: ReactDOMRe.Style.t=?,
    ~placement: placement=?,
    ~builtinPlacements: Js.Json.t=?, /* Object */
    ~defaultVisible: bool=?,
    ~visible: bool=?,
    ~onVisibleChange: bool => unit=?,
    ~mouseEnterDelay: int=?,
    ~mouseLeaveDelay: int=?,
    ~transitionName: string=?,
    ~trigger: string=?,
    ~openClassName: string=?,
    ~arrowPointAtCenter: bool=?,
    ~autoAdjustOverflow: bool=?, /* | Placement.adjustOverflow */
    /* getPopupContainer: Element => HTMLElement, */
    /* align?: TooltipAlignConfig */
    ~overlay: ReasonReact.reactElement=?,
    ~title: ReasonReact.reactElement=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~prefixCls=?,
      ~overlayClassName=?,
      ~style=?,
      ~overlayStyle=?,
      ~placement=?,
      ~builtinPlacements=?,
      ~defaultVisible=?,
      ~visible=?,
      ~onVisibleChange=?,
      ~mouseEnterDelay=?,
      ~mouseLeaveDelay=?,
      ~transitionName=?,
      ~trigger=?,
      ~openClassName=?,
      ~arrowPointAtCenter=?,
      ~autoAdjustOverflow=?,
      ~overlay=?,
      ~title=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~prefixCls?,
        ~overlayClassName?,
        ~style?,
        ~overlayStyle?,
        ~placement?,
        ~builtinPlacements?,
        ~defaultVisible?,
        ~visible?,
        ~onVisibleChange?,
        ~mouseEnterDelay?,
        ~mouseLeaveDelay?,
        ~transitionName?,
        ~trigger=?Js.Option.map((. b) => triggerToJs(b), trigger),
        ~openClassName?,
        ~arrowPointAtCenter?,
        ~autoAdjustOverflow?,
        ~overlay?,
        ~title?,
        (),
      ),
    children,
  );